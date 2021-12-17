#include "DeleteStatement.hpp"

namespace sql
{
    void DeleteStatement::accept(ExecuteVisitor &visitor)
    {
        visitor.visit(*this);
    }
    void DeleteStatement::set_TableName(std::string_view TableName)
    {
        this->TableName = TableName;
    }
    void DeleteStatement::write_data()
    {
        std::cout << "TableName " << TableName << '\n';
        for (auto &vector : columns)
        {
            std::cout << "Operand1 " << vector.Operand1 << ' ' << "Operation " << vector.Operation << ' ' << "Operand2 " << vector.Operand2 << '\n';
        }
    }
    const std::string& DeleteStatement::get_TableName()
    {
        return TableName;
    }
    void DeleteStatement::set_colomns(struct Expression a)
    {
        columns.emplace_back(std::move(a));
    }
    std::vector<Expression> DeleteStatement::get_colums()
    {
        return columns;
    }
}