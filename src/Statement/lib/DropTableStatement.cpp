#include "DropTableStatement.hpp"

namespace sql
{
    void DropTableStatement::Accept(ExecuteVisitor &visitor)
    {
        visitor.visit(*this);
    }
    void DropTableStatement::Write_Data()
    {
        std::cout << "TableName " << TableName << '\n';
    }
    
}