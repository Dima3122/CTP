#pragma once
#include "SqlStatement.hpp"
#include <string>

namespace sql
{
    class InsertStatement : public SqlStatement
    {
    private:
        std::string TableName;
        std::vector<ColumnDef> columns;
    public:
        InsertStatement();
        ~InsertStatement() = default;
        void get_data() override;
        void set_TableName(std::string_view TableName);
        std::string_view get_TableName();
        void set_colomns(struct ColumnDef a);
    };
}