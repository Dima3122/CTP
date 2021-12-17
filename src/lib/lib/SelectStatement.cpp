#include "SelectStatement.hpp"

namespace sql
{
    void SelectStatement::accept(ExecuteVisitor &visitor)
    {
        visitor.visit(*this);
    }
    void SelectStatement::write_data()
    {
        std::cout << "TableName " << TableName << '\n';
        for (auto &vector : columns)
        {
            std::cout << "Operand1 " << vector.Operand1 << ' ' << "Operation " << vector.Operation << ' ' << "Operand2 " << vector.Operand2 << '\n';
        }
    }
    void SelectStatement::set_TableName(std::string_view TableName)
    {
        this->TableName = TableName;
    }
    const std::string& SelectStatement::get_TableName()
    {
        return TableName;
    }
    void SelectStatement::set_colomns(Expression a)
    {
        columns.emplace_back(std::move(a));
    }

    std::vector<Expression> SelectStatement::get_colums()
    {
        return columns;
    }
}