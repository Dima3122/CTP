#pragma once
#include <iostream>
#include "Visitor.hpp"

namespace sql
{
    class ExecuteVisitor : public Visitor
    {
    public:
        void visit(CreateTableStatement &CreateStatement) override;
        void visit(SelectStatement &SelectStatement) override;
        void visit(InsertStatement &InsertStatement) override;
        void visit(DeleteStatement &DeleteStatement) override;
        void visit(DropTableStatement &DropStatement) override;

        ExecuteVisitor() = default;
        ~ExecuteVisitor() = default;
    };
}
