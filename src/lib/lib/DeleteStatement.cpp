#include "DeleteStatement.hpp"

namespace sql
{
    DeleteStatement::DeleteStatement()
    {
        
    }
    void DeleteStatement::execute()
    {
        
    }
    void DeleteStatement::set_TableName(std::string_view TableName)
    {
        this->TableName = TableName;
    }
    void DeleteStatement::get_data()
    {
        std::cout << "TableName " << TableName << std::endl;
        for (int i = 0; i < columns.size(); i++)
        {
            std::cout << "Operand1 " << columns[i].Operand1 << " "
                      << "Operation " << columns[i].Operation << " "
                      << "Operand2 " << columns[i].Operand2 << std::endl;
        }
    }
    std::string DeleteStatement::get_TableName()
    {
        return TableName;
    }
    void DeleteStatement::set_colomns(struct Expression a)
    {
        columns.emplace_back(a);
    }
    std::vector<Expression> DeleteStatement::get_colums()
    {
        return columns;
    }
}