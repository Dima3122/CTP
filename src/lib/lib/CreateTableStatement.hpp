#pragma once
#include "SqlStatement.hpp"
#include <string>

namespace sql
{
    class CreateTableStatement : public SqlStatement
    {
    private:
        std::string TableName;
        std::vector<ColumnDef> columns;
    public:
        CreateTableStatement();
        ~CreateTableStatement() = default;
        void get_data() override;
        void set_TableName(std::string_view TableName);
        void set_colomns(struct ColumnDef a);
    };
}