#include "Parser.hpp"

std::unique_ptr<sql::SqlStatement> ParseDropTableStatement(sql::NewLexer &lexer, SqlScript &result)
{
    std::unique_ptr<sql::DeleteStatement> StatementDelete = std::make_unique<sql::DeleteStatement>();
    sql::Token token = lexer.GetToken();
    Error error;
    if (!(token.Type == sql::TokenType::Keyword && token.Lexem == "Drop"))
    {
        error.expected = "";
        error.str = "";
        error.type = "";
        result.Errors.push_back(error);
    }
    token = lexer.GetToken();
    if (!(token.Type == sql::TokenType::Keyword && token.Lexem == "Table"))
    {
        error.expected = "";
        error.str = "";
        error.type = "";
        result.Errors.push_back(error);
    }
    token = lexer.GetToken();
    if (token.Type != sql::TokenType::ID)
    {
        error.expected = "";
        error.str = "";
        error.type = "";
        result.Errors.push_back(error);
    }
    StatementDelete->set_TableName(token.Lexem);
    token = lexer.GetToken();
    if (token.Type != sql::TokenType::Semicolon)
    {
        error.expected = "";
        error.str = "";
        error.type = "";
        result.Errors.push_back(error);
    }
    return std::unique_ptr<sql::DeleteStatement>(StatementDelete.release());
}

std::unique_ptr<sql::SqlStatement> ParseCreateTableStatement(sql::NewLexer &lexer, SqlScript &result)
{
    std::unique_ptr<sql::CreateTableStatement> StatementCreate = std::make_unique<sql::CreateTableStatement>();
    sql::Token token = lexer.GetToken();
    Error error;
    if (!(token.Type == sql::TokenType::Keyword && token.Lexem == "Drop"))
    {
        error.expected = "";
        error.str = "";
        error.type = "";
        result.Errors.push_back(error);
    }
    token = lexer.GetToken();
    if (!(token.Type == sql::TokenType::Keyword && token.Lexem == "Table"))
    {
        error.expected = "";
        error.str = "";
        error.type = "";
        result.Errors.push_back(error);
    }
    token = lexer.GetToken();
    if (token.Type != sql::TokenType::ID)
    {
        error.expected = "";
        error.str = "";
        error.type = "";
        result.Errors.push_back(error);
    }
    StatementCreate->set_TableName(token.Lexem);
    token = lexer.GetToken();
    if (token.Type != sql::TokenType::Semicolon)
    {
        error.expected = "";
        error.str = "";
        error.type = "";
        result.Errors.push_back(error);
    }
    return std::unique_ptr<sql::SqlStatement>(StatementCreate.release());
}

std::unique_ptr<sql::SqlStatement> ParseSelectTableStatement(sql::NewLexer &lexer, SqlScript &result)
{
    std::unique_ptr<sql::SelectStatement> StatementSelect = std::make_unique<sql::SelectStatement>();
    sql::Token token = lexer.GetToken();
    Error error;
    if (!(token.Type == sql::TokenType::Keyword && token.Lexem == "Drop"))
    {
        error.expected = "";
        error.str = "";
        error.type = "";
        result.Errors.push_back(error);
    }
    token = lexer.GetToken();
    if (!(token.Type == sql::TokenType::Keyword && token.Lexem == "Table"))
    {
        error.expected = "";
        error.str = "";
        error.type = "";
        result.Errors.push_back(error);
    }
    token = lexer.GetToken();
    if (token.Type != sql::TokenType::ID)
    {
        error.expected = "";
        error.str = "";
        error.type = "";
        result.Errors.push_back(error);
    }
    StatementSelect->set_TableName(token.Lexem);
    token = lexer.GetToken();
    if (token.Type != sql::TokenType::Semicolon)
    {
        error.expected = "";
        error.str = "";
        error.type = "";
        result.Errors.push_back(error);
    }
    return std::unique_ptr<sql::SqlStatement>(StatementSelect.release());
}

std::unique_ptr<sql::SqlStatement> ParseInsertTableStatement(sql::NewLexer &lexer, SqlScript &result)
{
    std::unique_ptr<sql::InsertStatement> StatementInsert = std::make_unique<sql::InsertStatement>();
    sql::Token token = lexer.GetToken();
    Error error;
    if (!(token.Type == sql::TokenType::Keyword && token.Lexem == "Drop"))
    {
        error.expected = "";
        error.str = "";
        error.type = "";
        result.Errors.push_back(error);
    }
    token = lexer.GetToken();
    if (!(token.Type == sql::TokenType::Keyword && token.Lexem == "Table"))
    {
        error.expected = "";
        error.str = "";
        error.type = "";
        result.Errors.push_back(error);
    }
    token = lexer.GetToken();
    if (token.Type != sql::TokenType::ID)
    {
        error.expected = "";
        error.str = "";
        error.type = "";
        result.Errors.push_back(error);
    }
    //StatementInsert->TableName = token.Lexem;
    StatementInsert->set_TableName(token.Lexem);
    if (token.Type != sql::TokenType::Semicolon)
    {
        error.expected = "";
        error.str = "";
        error.type = "";
        result.Errors.push_back(error);
    }
    return std::unique_ptr<sql::InsertStatement>(StatementInsert.release());
}

std::unique_ptr<sql::SqlStatement> ParseDeleteTableStatement(sql::NewLexer &lexer, SqlScript &result)
{
    std::unique_ptr<sql::DeleteStatement> StatementDelete = std::make_unique<sql::DeleteStatement>();
    sql::Token token = lexer.GetToken();
    Error error;
    if (!(token.Type == sql::TokenType::Keyword && token.Lexem == "Drop"))
    {
        error.expected = "";
        error.str = "";
        error.type = "";
        result.Errors.push_back(error);
    }
    token = lexer.GetToken();
    if (!(token.Type == sql::TokenType::Keyword && token.Lexem == "Table"))
    {
        error.expected = "";
        error.str = "";
        error.type = "";
        result.Errors.push_back(error);
    }
    token = lexer.GetToken();
    if (token.Type != sql::TokenType::ID)
    {
        error.expected = "";
        error.str = "";
        error.type = "";
        result.Errors.push_back(error);
    }
    StatementDelete->set_TableName(token.Lexem);
    token = lexer.GetToken();
    if (token.Type != sql::TokenType::Semicolon)
    {
        error.expected = "";
        error.str = "";
        error.type = "";
        result.Errors.push_back(error);
    }
    return std::unique_ptr<sql::DeleteStatement>(StatementDelete.release());
}

SqlScript run_parse(std::string str)
{
    SqlScript result;
    sql::NewLexer lexer(str);
    sql::Token token;
    Error error;
    do
    {
        token = lexer.PeekToken();
        if (token.Type == sql::TokenType::Keyword && token.Lexem == "CREATE")
        {
            result.Statements.emplace_back(ParseCreateTableStatement(lexer, result));
        }
        else if (token.Type == sql::TokenType::Keyword && token.Lexem == "SELECT")
        {
            result.Statements.emplace_back(ParseSelectTableStatement(lexer, result));
        }
        else if (token.Type == sql::TokenType::Keyword && token.Lexem == "INSERT")
        {
            result.Statements.emplace_back(ParseInsertTableStatement(lexer, result));
        }
        else if (token.Type == sql::TokenType::Keyword && token.Lexem == "DELETE")
        {
            result.Statements.emplace_back(ParseDeleteTableStatement(lexer, result));
        }
        else if (token.Type == sql::TokenType::Keyword && token.Lexem == "DROP")
        {
            result.Statements.emplace_back(ParseDropTableStatement(lexer, result));
        }
        else
        {
            error.expected = "";
            error.str = "";
            error.type = "";
            result.Errors.push_back(error);
        }

    } while (token.Type != sql::TokenType::FinalToken);
    return result;
}
