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
            std::cout << "column Name " << columns[i].ColumnName << " " << "column type " << columns[i].TypeName << std::endl; 
        }
    }
    std::string DeleteStatement::get_TableName()
    {
        return TableName;
    }
    void DeleteStatement::set_colomns(struct ColumnDef a)
    {
        columns.emplace_back(a);
    }
    std::vector<ColumnDef> DeleteStatement::get_colums()
    {
        return columns;
    }
}