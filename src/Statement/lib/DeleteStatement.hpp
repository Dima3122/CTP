#pragma once
#include "SqlStatement.hpp"
#include <string>

namespace sql
{
    class DeleteStatement : public SqlStatement
    {
    private:
        std::vector<Expression> columns;
    public:
        void Write_Data() override;
        void Set_Colomns(Expression a);
        const std::vector<Expression>& Get_Colums() const;
        void Accept(ExecuteVisitor &visitor) override;
    };
}