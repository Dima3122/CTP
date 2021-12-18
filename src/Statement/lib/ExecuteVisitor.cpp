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
        CreateStatement.Write_Data();
    }
    void ExecuteVisitor::visit(SelectStatement &SelectStatement)
    {
        SelectStatement.Write_Data();
    }
    void ExecuteVisitor::visit(InsertStatement &InsertStatement)
    {
        InsertStatement.Write_Data();
    }
    void ExecuteVisitor::visit(DeleteStatement &DeleteStatement)
    {
        DeleteStatement.Write_Data();
    }
    void ExecuteVisitor::visit(DropTableStatement &DropStatement)
    {
        DropStatement.Write_Data();
    }
}