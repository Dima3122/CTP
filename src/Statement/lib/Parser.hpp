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

namespace sql
{
    using SqlStatementPtr = std::unique_ptr<sql::SqlStatement>;
    using SqlStatements = std::vector<SqlStatementPtr>; 
    
    struct Error
    {
        std::string str;
        std::string type;
        std::string expected;
    };
    struct SqlScript
    {
        SqlStatements Statements;
        std::vector<Error> Errors;
    };
    
    class Parser
    {
    private:
        sql::Lexer &lexer;
        SqlScript result;
    public:
        Parser(sql::Lexer& lexer_) : lexer(lexer_){}
        SqlStatementPtr ParseCreateTableStatement();
        SqlStatementPtr ParseSelectTableStatement();
        SqlStatementPtr ParseDeleteTableStatement();
        SqlStatementPtr ParseDropTableStatement();
        SqlStatementPtr ParseInsertTableStatement();
    };
    SqlScript Parse_str(std::string str);
}
