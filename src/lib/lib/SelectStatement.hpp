#pragma once
#include "SqlStatement.hpp"
#include <string>

namespace sql
{
    class SelectStatement : public SqlStatement
    {
    private:
        std::string TableName;

    public:
        SelectStatement();
        ~SelectStatement() = default;

        void set_TableName(std::string_view TableName);
        std::string_view get_TableName();
    };
}