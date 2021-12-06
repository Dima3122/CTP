#include "DeleteStatement.hpp"

namespace sql
{
    DeleteStatement::DeleteStatement()
    {

    }

    void DeleteStatement::set_TableName(std::string_view TableName)
    {
        this->TableName = TableName;
    }
}