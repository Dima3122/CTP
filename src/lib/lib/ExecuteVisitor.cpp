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
    }
    void ExecuteVisitor::visit(InsertStatement &InsertStatement)
    {
    }
    void ExecuteVisitor::visit(DeleteStatement &DeleteStatement)
    {
    }
    void ExecuteVisitor::visit(DropTableStatement &DropStatement)
    {
        DropStatement.write_data();
    }
}