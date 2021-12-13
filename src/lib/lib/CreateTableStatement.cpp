#include "CreateTableStatement.hpp"

namespace sql
{
    void CreateTableStatement::accept(ExecuteVisitor &visitor)
    {
        visitor.visit(*this);
    }
    void CreateTableStatement::set_TableName(std::string_view TableName)
    {
        this->TableName = TableName;
    }
    void CreateTableStatement::write_data()
    {
        std::cout << "TableName " << TableName << '\n';
        for (auto &vector : columns)
        {
            std::cout << "column Name " << vector.ColumnName << ' ' << "column type " << vector.TypeName_or_value << '\n';
        }
        
    }
    void CreateTableStatement::set_colomns(struct ColumnDef a)
    {
        columns.emplace_back(std::move(a));
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