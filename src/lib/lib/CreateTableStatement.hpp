#pragma once
#include "SqlStatement.hpp"
#include <string>
//CREATE TABLE users (name TEXT, age INT);
namespace sql
{
    class CreateTableStatement: public SqlStatement
    {
        private:
            std::string sql_inquiry;
        public:
        void get_all_tokens();
        CreateTableStatement();
        CreateTableStatement(std::string sql_inquiry);

        std::string Create_Statement(std::string TableName, std::string *TypeName, std::string *value, int count_value);
        ~CreateTableStatement();
    };
}