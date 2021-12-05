#include "Parser.hpp"

namespace sql
{
    Parser::Parser()
    {
    }

    std::unique_ptr<sql::SqlStatement> Parser::ParseDropTableStatement(NewLexer &lexer)
    {
        std::unique_ptr<DeleteStatement> StatementDelete = std::make_unique<DeleteStatement>();
        Token token = lexer.GetToken();
        if (!(token.Type == TokenType::Keyword && token.Lexem == "Drop"))
        {
            /* code */
        }
        token = lexer.GetToken();
        if (!(token.Type == TokenType::Keyword && token.Lexem == "Table"))
        {
            /* code */
        }
        token = lexer.GetToken();
        if (token.Type != TokenType::ID)
        {
            /* code */
        }
        StatementDelete->set_TableName(token.Lexem);
        token = lexer.GetToken();
        if (token.Type != TokenType::Semicolon)
        {
            /* code */
        }
        return std::unique_ptr<sql::DeleteStatement>(StatementDelete.release());
    }

    std::unique_ptr<SqlStatement> Parser::ParseCreateTableStatement(NewLexer &lexer)
    {
        std::unique_ptr<CreateTableStatement> StatementCreate = std::make_unique<CreateTableStatement>();
        Token token = lexer.GetToken();
        if (!(token.Type == TokenType::Keyword && token.Lexem == "Drop"))
        {
            /* code */
        }
        token = lexer.GetToken();
        if (!(token.Type == TokenType::Keyword && token.Lexem == "Table"))
        {
            /* code */
        }
        token = lexer.GetToken();
        if (token.Type != TokenType::ID)
        {
            /* code */
        }
        StatementCreate->set_TableName(token.Lexem);
        token = lexer.GetToken();
        if (token.Type != TokenType::Semicolon)
        {
            /* code */
        }
        return std::unique_ptr<SqlStatement>(StatementCreate.release());
    }

    std::unique_ptr<SqlStatement> Parser::ParseSelectTableStatement(NewLexer &lexer)
    {
        std::unique_ptr<sql::SelectStatement> StatementSelect = std::make_unique<sql::SelectStatement>();
        Token token = lexer.GetToken();
        if (!(token.Type == TokenType::Keyword && token.Lexem == "Drop"))
        {
            /* code */
        }
        token = lexer.GetToken();
        if (!(token.Type == TokenType::Keyword && token.Lexem == "Table"))
        {
            /* code */
        }
        token = lexer.GetToken();
        if (token.Type != TokenType::ID)
        {
            /* code */
        }
        StatementSelect->set_TableName(token.Lexem);
        token = lexer.GetToken();
        if (token.Type != TokenType::Semicolon)
        {
            /* code */
        }
        return std::unique_ptr<sql::SqlStatement>(StatementSelect.release());
    }

    std::unique_ptr<SqlStatement> Parser::ParseInsertTableStatement(NewLexer &lexer)
    {
        std::unique_ptr<InsertStatement> StatementInsert = std::make_unique<InsertStatement>();
        Token token = lexer.GetToken();
        if (!(token.Type == TokenType::Keyword && token.Lexem == "Drop"))
        {
            /* code */
        }
        token = lexer.GetToken();
        if (!(token.Type == TokenType::Keyword && token.Lexem == "Table"))
        {
            /* code */
        }
        token = lexer.GetToken();
        if (token.Type != TokenType::ID)
        {
            /* code */
        }
        //StatementInsert->TableName = token.Lexem;
        StatementInsert->set_TableName(token.Lexem);
        if (token.Type != TokenType::Semicolon)
        {
            /* code */
        }
        return std::unique_ptr<InsertStatement>(StatementInsert.release());
    }

    std::unique_ptr<SqlStatement> Parser::ParseDeleteTableStatement(NewLexer &lexer)
    {
        std::unique_ptr<DeleteStatement> StatementDelete = std::make_unique<DeleteStatement>();
        Token token = lexer.GetToken();
        if (!(token.Type == TokenType::Keyword && token.Lexem == "Drop"))
        {
            /* code */
        }
        token = lexer.GetToken();
        if (!(token.Type == TokenType::Keyword && token.Lexem == "Table"))
        {
            /* code */
        }
        token = lexer.GetToken();
        if (token.Type != TokenType::Semicolon)
        {
            
        }
        return std::unique_ptr<DeleteStatement>(StatementDelete.release());
    }
    
    Parser::SqlScript Parser::run_parse(std::string str)
    {
        sql::NewLexer lexer(str);
        Token token;
        do
        {
            token = lexer.PeekToken();
            if (token.Type == TokenType::Keyword && token.Lexem == "CREATE")
            {
                
            }
            else if (token.Type == TokenType::Keyword && token.Lexem == "SELECT")
            {
                auto a = ParseSelectTableStatement(lexer);
            }
            else if (token.Type == TokenType::Keyword && token.Lexem == "INSERT")
            {
                auto a = ParseInsertTableStatement(lexer);
            }
            else if (token.Type == TokenType::Keyword && token.Lexem == "DELETE")
            {
                /* code */
            }
            else if (token.Type == TokenType::Keyword && token.Lexem == "DROP")
            {
                /* code */
            }
            else
            {
                
            }

        } while (token.Type != TokenType::FinalToken);
        // return Parser::Script;
    }
}