#include "SelectStatement.hpp"

namespace sql
{
    SelectStatement::SelectStatement()
    {

    }
    void SelectStatement::set_TableName(std::string_view TableName)
    {
        this->TableName = TableName; 
    }

    std::string_view SelectStatement::get_TableName()
    {
        return TableName;
    }
}