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
        SelectStatement();
        ~SelectStatement() = default;
        
        void get_data() override;
        void set_TableName(std::string_view TableName);
        void set_colomns(struct Expression a);
        
        std::string get_TableName() override;
        std::vector<Expression> get_colums();
        
        void accept(Visitor &visitor) override;
    };
}