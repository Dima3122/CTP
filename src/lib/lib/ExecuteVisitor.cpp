#include "ExecuteVisitor.hpp"
#include "SqlStatement.hpp"
#include "CreateTableStatement.hpp"
#include "SelectStatement.hpp"
#include "InsertStatement.hpp"
#include "DeleteStatement.hpp"
#include "DropTableStatement.hpp"

namespace sql
{
    ExecuteVisitor::ExecuteVisitor()
    {
    }
    void ExecuteVisitor::visit(CreateTableStatement &CreateStatement)
    {
        CreateStatement.get_data();
    }
    void ExecuteVisitor::visit(SelectStatement &SelectStatement)
    {
    }
    void ExecuteVisitor::visit(InsertStatement &InsertStatement)
    {
    }
    void ExecuteVisitor::visit(DeleteStatement &DeleteStatement)
    {
    }
    void ExecuteVisitor::visit(DropTableStatement &DropStatement)
    {
        DropStatement.get_data();
    }
}