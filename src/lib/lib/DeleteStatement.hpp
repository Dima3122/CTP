#pragma once
#include "SqlStatement.hpp"
#include <string>

namespace sql
{
    class DeleteStatement : public SqlStatement
    {
    private:
        std::string TableName;
        std::vector<ColumnDef> columns;
    public:
        DeleteStatement();
        ~DeleteStatement() = default;
        void get_data() override;
        void set_TableName(std::string_view TableName);
        void set_colomns(struct ColumnDef a);
    };
}