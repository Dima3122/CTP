#pragma once
#include "SqlStatement.hpp"

namespace sql
{
    class DropTableStatement: public SqlStatement
    {
        public:
            void Create_str() override;
    };
}