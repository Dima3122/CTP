#pragma once
#include <vector>
#include <memory>
#include "NewLexer.hpp"
#include "InsertStatement.hpp"
#include "DropTableStatement.hpp"
#include "DeleteStatement.hpp"
#include "SelectStatement.hpp"
#include "CreateTableStatement.hpp"
#include "SqlStatement.hpp"

namespace sql
{
    class Parser
    {
    private:
        struct Error
        {
            std::string str;
            std::string type;
            std::string expected;
        };
        struct SqlScript
        {
            std::vector<std::unique_ptr<SqlStatement>> Statements;
            std::vector<Error> Errors;
        };
        SqlScript Script;
        std::unique_ptr<SqlStatement> ParseCreateTableStatement(NewLexer &lexer);
        std::unique_ptr<SqlStatement> ParseSelectTableStatement(NewLexer &lexer);
        std::unique_ptr<SqlStatement> ParseDeleteTableStatement(NewLexer &lexer);
        std::unique_ptr<SqlStatement> ParseDropTableStatement(NewLexer &lexer);
        std::unique_ptr<SqlStatement> ParseInsertTableStatement(NewLexer &lexer);

    public:
        Parser::SqlScript run_parse(std::string str);
        Parser();
        ~Parser() = default;
    };
}