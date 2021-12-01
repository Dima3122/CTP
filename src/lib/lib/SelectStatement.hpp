#pragma once
#include "SqlStatement.hpp"

namespace sql
{
    class SelectStatement : public SqlStatement
    {
    public:
        SelectStatement();
        ~SelectStatement();

        void Create_str() override;
    };
}
