#include <iostream>
// #include "InsertStatement.hpp"
// #include "DropTableStatement.hpp"
// #include "DeleteStatement.hpp"
// #include "SelectStatement.hpp"
// #include "CreateTableStatement.hpp"
// #include "SqlStatement.hpp"

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
    };

    // class ExecuteVisitor : public Visitor
    // {
    // public:
    //     void visit(sql::CreateTableStatement &CreateStatement) override;
    //     void visit(sql::SelectStatement &SelectStatement) override;
    //     void visit(sql::InsertStatement &InsertStatement) override;
    //     void visit(sql::DeleteStatement &DeleteStatement) override;
    //     void visit(sql::DropTableStatement &DropStatement) override;

    //     ExecuteVisitor();
    //     ~ExecuteVisitor() = default;
    // };
}
