#pragma once
#include "SqlStatement.cpp"

namespace sql
{
    class SelectStatement : public SqlStatement
    {
        SelectStatement();
        ~SelectStatement();
    };
}