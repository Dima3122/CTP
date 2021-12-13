#include "ExecuteVisitor.hpp"
#include "SqlStatement.hpp"
#include "CreateTableStatement.hpp"
#include "SelectStatement.hpp"
#include "InsertStatement.hpp"
#include "DeleteStatement.hpp"
#include "DropTableStatement.hpp"

namespace sql
{
    void ExecuteVisitor::visit(CreateTableStatement &CreateStatement)
    {
        CreateStatement.write_data();
    }
    void ExecuteVisitor::visit(SelectStatement &SelectStatement)
    {
        SelectStatement.write_data();
    }
    void ExecuteVisitor::visit(InsertStatement &InsertStatement)
    {
        InsertStatement.write_data();
    }
    void ExecuteVisitor::visit(DeleteStatement &DeleteStatement)
    {
        DeleteStatement.write_data();
    }
    void ExecuteVisitor::visit(DropTableStatement &DropStatement)
    {
        DropStatement.write_data();
    }
}