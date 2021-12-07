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
            void get_data() override;
            void set_TableName(std::string_view TableName) override;
    };
}