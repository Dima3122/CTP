#include "InsertStatement.hpp"

namespace sql
{
    void InsertStatement::Accept(ExecuteVisitor &visitor)
    {
        visitor.visit(*this);
    }
    void InsertStatement::Write_Data()
    {
        std::cout << "TableName " << TableName << '\n';
        for (const auto &column : columns)
        {
            std::cout << "column Name " << column.ColumnName << ' ' << "column type " << column.TypeName_or_value << '\n';
        }
    }
    void InsertStatement::Set_Colomns(ColumnDef a)
    {
        columns.emplace_back(std::move(a));
    }
    const std::vector<ColumnDef>& InsertStatement::Get_Colums() const
    {
        return columns;
    }
}