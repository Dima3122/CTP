#include "ExecuteVisitor.hpp"

namespace sql
{
    ExecuteVisitor::ExecuteVisitor()
    {
        
    }
    void ExecuteVisitor::visit(sql::CreateTableStatement &CreateStatement)
    {

    }
    void ExecuteVisitor::visit(sql::SelectStatement &SelectStatement)
    {

    }
    void ExecuteVisitor::visit(sql::InsertStatement &InsertStatement)
    {

    }
    void ExecuteVisitor::visit(sql::DeleteStatement &DeleteStatement)
    {

    }
    void ExecuteVisitor::visit(sql::DropTableStatement &DropStatement)
    {
        // DropStatement.get_data();
    }
}