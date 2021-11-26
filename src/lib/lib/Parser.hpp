#pragma once
#include <vector>

#include "SqlStatement.cpp"
#include "NewLexer.hpp"
#include "Error.cpp"

namespace sql
{
    class Parser : public SqlStatement
    {
    private:
        std::string sql_inquiry;
        sql::NewLexer lexer;
        sql::Token *Tokens;
    public:
        Parser(std::string sql_inquiry);
        ~Parser();

        void initial_sql_statements();
        int get_all_tokens();
        void run_parse();
    };
}