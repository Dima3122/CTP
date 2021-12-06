#include <vector>
#include <memory>
#include <NewLexer.hpp>
#include <InsertStatement.hpp>
#include <DropTableStatement.hpp>
#include <DeleteStatement.hpp>
#include <SelectStatement.hpp>
#include <CreateTableStatement.hpp>
#include <SqlStatement.hpp>

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
struct ColumnDef
{
    std::string ColumnName;
    std::string TypeName;
};
std::unique_ptr<sql::SqlStatement> ParseCreateTableStatement(sql::NewLexer &lexer, SqlScript &result);
std::unique_ptr<sql::SqlStatement> ParseSelectTableStatement(sql::NewLexer &lexer, SqlScript &result);
std::unique_ptr<sql::SqlStatement> ParseDeleteTableStatement(sql::NewLexer &lexer, SqlScript &result);
std::unique_ptr<sql::SqlStatement> ParseDropTableStatement(sql::NewLexer &lexer, SqlScript &result);
std::unique_ptr<sql::SqlStatement> ParseInsertTableStatement(sql::NewLexer &lexer, SqlScript &result);
SqlScript run_parse(std::string str);
