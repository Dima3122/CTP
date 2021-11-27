#pragma once
#include <vector>
#include "InsertStatement.hpp"
#include "DropTableStatement.hpp"
#include "DeleteStatement.hpp"
#include "SelectStatement.hpp"
#include "CreateTableStatement.hpp"
#include "SqlStatement.hpp"
#include "NewLexer.hpp"

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
        Parser();
        ~Parser();

        int get_all_tokens();
        void run_parse();
    };
}