#include "CreateTableStatement.hpp"

namespace sql
{
    CreateTableStatement::CreateTableStatement(std::string sql_inquiry)
    {
        this->sql_inquiry = sql_inquiry;
    }
    CreateTableStatement::CreateTableStatement()
    {
    }
    
    std::string CreateTableStatement::Create_Statement(std::string TableName, std::string *TypeName, std::string *value, int count_value)
    {
        std::string result;
        result = "CREATE TABLE " + TableName + " (";
        for (int i = 0; i < count_value; i++)
        {
            if (i == count_value - 1)
            {
                result += TypeName[i] + " " + value[i];
            }
            else
            {
                result += TypeName[i] + " " + value[i] + ", ";
            }
        }
        result += ");";
        return result;
    }

    CreateTableStatement::~CreateTableStatement()
    {
    }
}