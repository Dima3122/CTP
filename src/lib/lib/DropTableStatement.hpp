#pragma once
#include "SqlStatement.hpp"

namespace sql
{
    class DropTableStatement : public SqlStatement
    {
    private:
        std::string TableName;
        std::vector<ColumnDef> columns;
        std::vector<ColumnDef> get_colums();
        void set_colomns(struct ColumnDef a);

    public:
        DropTableStatement();
        ~DropTableStatement() = default;
        
        void get_data() override;
        void set_TableName(std::string_view TableName);
        std::string get_TableName() override;
        
        void execute(/*rdb::Database& db*/) override;
    };
}