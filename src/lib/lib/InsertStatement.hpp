#pragma once
#include "SqlStatement.hpp"
#include <string>

namespace sql
{
    class InsertStatement : public SqlStatement
    {
    private:
        std::string_view TableName;
    public:
        InsertStatement() = default;
        ~InsertStatement() = default;

        void set_TableName(std::string_view TableName)
        {
            this->TableName = TableName;
        }
        std::string_view get_TableName();
    };
}