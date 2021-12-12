#pragma once
#include <iostream>
#include "Visitor.hpp"
namespace sql
{
    class ExecuteVisitor : public Visitor
    {
    public:
        void visit(sql::CreateTableStatement &CreateStatement) override;
        void visit(sql::SelectStatement &SelectStatement) override;
        void visit(sql::InsertStatement &InsertStatement) override;
        void visit(sql::DeleteStatement &DeleteStatement) override;
        void visit(sql::DropTableStatement &DropStatement) override;

        ExecuteVisitor();
        ~ExecuteVisitor() = default;
    };
}
