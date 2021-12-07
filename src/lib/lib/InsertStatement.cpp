#include "InsertStatement.hpp"

namespace sql
{
    InsertStatement::InsertStatement()
    {
    }

    void InsertStatement::set_TableName(std::string_view TableName)
    {
        this->TableName = TableName;
    }
    void InsertStatement::get_data()
    {
        std::cout << "TableName " << TableName << std::endl;
        for (int i = 0; i < columns.size(); i++)
        {
            std::cout << "column Name " << columns[i].ColumnName << " "
                      << "column type " << columns[i].TypeName << std::endl;
        }
    }
    void InsertStatement::set_colomns(struct ColumnDef a)
    {
        columns.emplace_back(a);
    }
    std::string InsertStatement::get_TableName()
    {
        return TableName;
    }
}