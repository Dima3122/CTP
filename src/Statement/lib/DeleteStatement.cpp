#include "DeleteStatement.hpp"

namespace sql
{
    void DeleteStatement::Accept(ExecuteVisitor &visitor)
    {
        visitor.visit(*this);
    }
    void DeleteStatement::Write_Data()
    {
        std::cout << "TableName " << TableName << '\n';
        for (const auto &column : columns)
        {
            std::cout << "Operand1 " << column.Operand1 << ' ' << "Operation " << column.Operation << ' ' << "Operand2 " << column.Operand2 << '\n';
        }
    }
    void DeleteStatement::Set_Colomns(Expression a)
    {
        columns.emplace_back(std::move(a));
    }
    const std::vector<Expression>& DeleteStatement::Get_Colums() const
    {
        return columns;
    }
}