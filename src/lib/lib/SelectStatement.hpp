#pragma once
#include "SqlStatement.hpp"
#include <string>

namespace sql
{
    class SelectStatement : public SqlStatement
    {
    private:
        std::string TableName;
        std::vector<ColumnDef> columns;
    public:
        SelectStatement();
        ~SelectStatement() = default;
        void get_data() override;
        void set_TableName(std::string_view TableName) override;
        std::string get_TableName();
        void set_colomns(struct ColumnDef a) override;
    };
}