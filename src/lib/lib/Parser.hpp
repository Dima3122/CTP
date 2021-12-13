#include <vector>
#include <memory>
#include "Lexer.hpp"
#include "InsertStatement.hpp"
#include "DropTableStatement.hpp"
#include "DeleteStatement.hpp"
#include "SelectStatement.hpp"
#include "CreateTableStatement.hpp"
#include "SqlStatement.hpp"
#include "Visitor.hpp"

struct Error
{
    std::string str;
    std::string type;
    std::string expected;
};
struct SqlScript
{
    std::vector<std::unique_ptr<sql::SqlStatement>> Statements;
    std::vector<Error> Errors;
};

std::unique_ptr<sql::SqlStatement> ParseCreateTableStatement(sql::Lexer &lexer, SqlScript &result);
std::unique_ptr<sql::SqlStatement> ParseSelectTableStatement(sql::Lexer &lexer, SqlScript &result);
std::unique_ptr<sql::SqlStatement> ParseDeleteTableStatement(sql::Lexer &lexer, SqlScript &result);
std::unique_ptr<sql::SqlStatement> ParseDropTableStatement(sql::Lexer &lexer, SqlScript &result);
std::unique_ptr<sql::SqlStatement> ParseInsertTableStatement(sql::Lexer &lexer, SqlScript &result);
SqlScript run_parse(std::string str);
