#pragma once
#include "SqlStatement.hpp"
#include <string>

namespace sql
{
    class DeleteStatement : public SqlStatement
    {
    private:
        std::string TableName;
        std::vector<Expression> columns;
    public:
        DeleteStatement() = default;
        ~DeleteStatement() = default;
        void write_data() override;
        void set_TableName(std::string_view TableName);
        void set_colomns(Expression a);

        const std::string& get_TableName() override;
        std::vector<Expression> get_colums();

        void accept(ExecuteVisitor &visitor) override;
    };
}