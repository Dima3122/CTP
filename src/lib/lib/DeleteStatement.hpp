#pragma once
#include "SqlStatement.hpp"

namespace sql
{  
    class DeleteStatement: public SqlStatement
    {
        void Create_str() override;
    };
}