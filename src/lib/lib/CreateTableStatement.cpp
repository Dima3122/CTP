#include "CreateTableStatement.hpp"

namespace sql
{
    CreateTableStatement::CreateTableStatement()
    {
    }

    void CreateTableStatement::execute(/*rdb::Database& db*/)
    {

    }
    void CreateTableStatement::set_TableName(std::string_view TableName)
    {
        this->TableName = TableName;
    }
    void CreateTableStatement::get_data()
    {
        std::cout << "TableName " << TableName << std::endl;
        for (int i = 0; i < columns.size(); i++)
        {
            std::cout << "column Name " << columns[i].ColumnName << " "
                      << "column type " << columns[i].TypeName << std::endl;
        }
    }
    void CreateTableStatement::set_colomns(struct ColumnDef a)
    {
        columns.emplace_back(a);
    }

    std::string CreateTableStatement::get_TableName()
    {
        return TableName;
    }
    std::vector<ColumnDef> CreateTableStatement::get_colums()
    {
        return columns;
    }
}