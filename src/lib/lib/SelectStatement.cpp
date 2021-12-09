#include "SelectStatement.hpp"

namespace sql
{
    SelectStatement::SelectStatement()
    {
    }

    void SelectStatement::execute()
    {
        
    }
    void SelectStatement::get_data()
    {
        std::cout << "TableName " << TableName << std::endl;
        for (int i = 0; i < columns.size(); i++)
        {
            std::cout << "Operand1 " << columns[i].Operand1 << " "
                      << "Operation " << columns[i].Operation << " "
                      << "Operand2 " << columns[i].Operand2 << std::endl;
        }
    }
    void SelectStatement::set_TableName(std::string_view TableName)
    {
        this->TableName = TableName;
    }
    std::string SelectStatement::get_TableName()
    {
        return TableName;
    }
    void SelectStatement::set_colomns(struct Expression a)
    {
        columns.emplace_back(a);
    }

    std::vector<Expression> SelectStatement::get_colums()
    {
        return columns;
    }
}