#pragma once
#include "SqlStatement.hpp"

namespace sql
{
    class DropTableStatement: public SqlStatement
    {
        private:
            std::string TableName;
        public:
            DropTableStatement();
            ~DropTableStatement() = default;  

            void set_TableName(std::string TableName);
    };
}