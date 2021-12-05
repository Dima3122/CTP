#pragma once
#include "SqlStatement.hpp"
#include <string>

namespace sql
{
    class CreateTableStatement: public SqlStatement
    {
        private:
            std::string TableName;
        public:
        CreateTableStatement() = default;
        void set_TableName(std::string_view TableName)
        {
            this->TableName = TableName;
        }
        ~CreateTableStatement() = default;
    };
}