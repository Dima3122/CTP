#include "SelectStatement.hpp"

namespace sql
{
    void SelectStatement::Accept(ExecuteVisitor &visitor)
    {
        visitor.visit(*this);
    }
    void SelectStatement::Write_Data()
    {
        std::cout << "TableName " << TableName << '\n';
        for (const auto &column : columns)
        {
            std::cout << "Operand1 " << column.Operand1 << ' ' << "Operation " << column.Operation << ' ' << "Operand2 " << column.Operand2 << '\n';
        }
    }
    void SelectStatement::Set_Colomns(Expression a)
    {
        columns.emplace_back(std::move(a));
    }

    const std::vector<Expression>& SelectStatement::Get_Colums() const
    {
        return columns;
    }
}