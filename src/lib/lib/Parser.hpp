#pragma once
#include "SqlStatement.cpp"
#include "NewLexer.hpp"
#include <vector>
#include "Error.cpp"

namespace sql
{
    class Parser
    {
    private:
        std::string sql_inquiry;
        sql::NewLexer lexer;
        sql::Token *Tokens;
    public:
        Parser(std::string sql_inquiry);
        ~Parser();
        
        int get_all_tokens();
        void run_parse();
    };
}