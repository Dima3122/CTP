#pragma once
#include <iostream>
// #include "Parser.hpp"

namespace sql
{
    class CreateTableStatement;
    class SelectStatement;
    class InsertStatement;
    class DeleteStatement;
    class DropTableStatement;

    class Visitor
    {
    public:
        virtual void visit(sql::CreateTableStatement &CreateStatement) = 0;
        virtual void visit(sql::SelectStatement &SelectStatement) = 0;
        virtual void visit(sql::InsertStatement &InsertStatement) = 0;
        virtual void visit(sql::DeleteStatement &DeleteStatement) = 0;
        virtual void visit(sql::DropTableStatement &DropStatement) = 0;
        virtual ~Visitor() = default;
        Visitor() = default;
    };
}
