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
        CreateTableStatement() = default;
        ~CreateTableStatement() = default;
        void write_data() override;

        void set_TableName(std::string_view TableName);
        void set_colomns(ColumnDef a);
        
        std::string get_TableName() override;
        std::vector<ColumnDef> get_colums();

        void accept(ExecuteVisitor &visitor) override;
    };
}