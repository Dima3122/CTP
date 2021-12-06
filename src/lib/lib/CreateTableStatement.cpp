#include "CreateTableStatement.hpp"

namespace sql
{
    CreateTableStatement::CreateTableStatement()
    {

    }
    void CreateTableStatement::set_TableName(std::string_view TableName)
    {
        this->TableName = TableName;
    }
}