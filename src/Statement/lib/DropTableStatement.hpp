#pragma once
#include "SqlStatement.hpp"

namespace sql
{
    class DropTableStatement : public SqlStatement
    {
    public:
        void Write_Data() override;        
        void Accept(ExecuteVisitor &visitor) override;
    };
}