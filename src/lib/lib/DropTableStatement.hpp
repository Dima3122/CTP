#pragma once
#include "SqlStatement.hpp"

namespace sql
{
    class DropTableStatement: public SqlStatement
    {
        public:
            ~DropTableStatement() = default;  
    };
}