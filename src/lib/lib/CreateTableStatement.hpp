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

        void set_TableName(std::string_view TableName) override;
        void set_colomns(struct ColumnDef a) override;
        
        std::string get_TableName() override;
        std::vector<ColumnDef> get_colums() override;

        void execute(/*rdb::Database& db*/) override;
    };
}