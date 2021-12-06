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
        InsertStatement();
        ~InsertStatement() = default;

        void set_TableName(std::string_view TableName);
        std::string_view get_TableName();
    };
}