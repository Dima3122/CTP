#pragma once
#include "SqlStatement.hpp"
#include <string>

namespace sql
{
    class SelectStatement : public SqlStatement
    {
    private:
        std::string TableName;
        std::vector<Expression> columns;
    public:
        SelectStatement() = default;
        ~SelectStatement() = default;
        
        void write_data() override;
        void set_TableName(std::string_view TableName);
        void set_colomns(Expression a);
        
        std::string get_TableName() override;
        std::vector<Expression> get_colums();
        
        void accept(ExecuteVisitor &visitor) override;
    };
}