#pragma once
#include "SqlStatement.hpp"
#include <string>

namespace sql
{
    class CreateTableStatement : public SqlStatement
    {
    private:
        std::vector<ColumnDef> columns;
    public:
        void Write_Data() override;
        void Set_Colomns(ColumnDef a);
        const std::vector<ColumnDef>& Get_Colums() const; 
        void Accept(ExecuteVisitor &visitor) override;
    };
}