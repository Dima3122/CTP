#include "DropTableStatement.hpp"

namespace sql
{
    DropTableStatement::DropTableStatement()
    {
    }
    void DropTableStatement::accept(Visitor &visitor)
    {
        visitor.visit(*this);
    }
    void DropTableStatement::set_colomns(struct ColumnDef a)
    {
        columns.emplace_back(a);
    }
    std::vector<ColumnDef> DropTableStatement::get_colums()
    {
        return columns;
    }
    void DropTableStatement::get_data()
    {
        std::cout << "TableName " << TableName << std::endl;
    }
    void DropTableStatement::set_TableName(std::string_view TableName)
    {
        this->TableName = TableName;
    }
    std::string DropTableStatement::get_TableName()
    {
        return TableName;
    }
}