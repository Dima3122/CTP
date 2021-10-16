#pragma once
#include "SqlStatement.hpp"
#include <string>
//CREATE TABLE users (name TEXT, age INT);
namespace sql
{
    class CreateTableStatement: public SqlStatement
    {
        private:
        public:
        //CreateTableStatement();
        std::string Create_Statement(std::string TableName, std::string *TypeName, std::string *value, int count_value);
        ~CreateTableStatement();
    };
}