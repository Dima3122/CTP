#include "DropTableStatement.hpp"

namespace sql
{
    DropTableStatement::DropTableStatement()
    {

    }    
    void DropTableStatement::set_TableName(std::string TableName)
    {
        this->TableName = TableName;
    }
}