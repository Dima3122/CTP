#include "InsertStatement.hpp"

namespace sql
{
    void InsertStatement::accept(ExecuteVisitor &visitor)
    {
        visitor.visit(*this);
    }
    void InsertStatement::set_TableName(std::string_view TableName)
    {
        this->TableName = TableName;
    }
    void InsertStatement::write_data()
    {
        std::cout << "TableName " << TableName << '\n';
        for (auto &vector : columns)
        {
            std::cout << "column Name " << vector.ColumnName << ' ' << "column type " << vector.TypeName_or_value << '\n';
        }
    }
    void InsertStatement::set_colomns(ColumnDef a)
    {
        columns.emplace_back(std::move(a));
    }
    const std::string& InsertStatement::get_TableName()
    {
        return TableName;
    }
    std::vector<ColumnDef> InsertStatement::get_colums()
    {
        return columns;
    }
}