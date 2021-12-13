#include "DropTableStatement.hpp"

namespace sql
{
    void DropTableStatement::accept(ExecuteVisitor &visitor)
    {
        visitor.visit(*this);
    }
    void DropTableStatement::write_data()
    {
        std::cout << "TableName " << TableName << '\n';
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