#pragma once
#include "SqlStatement.hpp"

namespace sql
{
    class DeleteStatement : public SqlStatement
    {
    private:
        std::string TableName;
    public:
        DeleteStatement() = default;
        ~DeleteStatement() = default;
        // void set_TableName(std::string_view TableName);
        void set_TableName(std::string_view TableName)
        {
            this->TableName = TableName;
        }
    };
}