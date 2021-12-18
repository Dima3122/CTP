#include "CreateTableStatement.hpp"

namespace sql
{
    void CreateTableStatement::Accept(ExecuteVisitor &visitor)
    {
        visitor.visit(*this);
    }
    void CreateTableStatement::Write_Data()
    {
        std::cout << "TableName " << TableName << '\n';
        for (const auto &column : columns)
        {
            std::cout << "column Name " << column.ColumnName << ' ' << "column type " << column.TypeName_or_value << '\n';
        }
    }
    void CreateTableStatement::Set_Colomns(ColumnDef a)
    {
        columns.emplace_back(std::move(a));
    }

    const std::vector<ColumnDef>& CreateTableStatement::Get_Colums() const
    {
        return columns;
    }
}