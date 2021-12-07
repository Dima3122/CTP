#include "SelectStatement.hpp"

namespace sql
{
    SelectStatement::SelectStatement()
    {
    }
    void SelectStatement::get_data()
    {
        std::cout << "TableName " << TableName << std::endl;
        for (int i = 0; i < columns.size(); i++)
        {
            std::cout << "column Name " << columns[i].ColumnName << " "
                      << "column type " << columns[i].TypeName << std::endl;
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
    void SelectStatement::set_colomns(struct ColumnDef a)
    {
        columns.emplace_back(a);
    }

    std::vector<ColumnDef> SelectStatement::get_colums()
    {
        return columns;
    }
}