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
    public:
        Parser();
        ~Parser();

        void ParseCreateTableStatement(NewLexer& lexer);
        void ParseSelectTableStatement(NewLexer& lexer);
        void ParseDeleteTableStatement(NewLexer& lexer);
        void ParseDropTableStatement(NewLexer& lexer);
        void ParseInsertTableStatement(NewLexer& lexer);
        void run_parse(std::string_view str);
    };
}