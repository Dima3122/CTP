#include "InsertStatement.hpp"

namespace sql
{
    InsertStatement::InsertStatement()
    {
    }

    void InsertStatement::set_TableName(std::string_view TableName)
    {
        this->TableName = TableName;
    }
    
    std::string_view InsertStatement::get_TableName()
    {
        return TableName;
    }
}