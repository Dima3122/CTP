#pragma once
#include "SqlStatement.hpp"

namespace sql
{
    class DropTableStatement : public SqlStatement
    {
    private:
        std::string TableName;
        std::vector<ColumnDef> columns;

    public:
        DropTableStatement() = default;
        ~DropTableStatement() = default;
        
        void write_data() override;
        void set_TableName(std::string_view TableName);
        std::string get_TableName() override;
        
        void accept(ExecuteVisitor &visitor) override;
    };
}