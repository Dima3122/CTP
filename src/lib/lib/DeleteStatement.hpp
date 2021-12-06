#pragma once
#include "SqlStatement.hpp"
#include <string>

namespace sql
{
    class DeleteStatement : public SqlStatement
    {
    private:
        std::string TableName;
    public:
        DeleteStatement();
        ~DeleteStatement() = default;
        void set_TableName(std::string_view TableName);
    };
}