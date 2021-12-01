#include "Parser.hpp"

namespace sql
{
    Parser::Parser()
    {
        sql_statements.push_back(new CreateTableStatement());
        sql_statements.push_back(new InsertStatement());
        //sql_statements.push_back(new SelectStatement());
        //sql_statements.push_back(new DeleteStatement());
        //sql_statements.push_back(new DropTableStatement());
    }

    void Parser::ParseDropTableStatement(NewLexer& lexer)
    {
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
            /* code */
        }
        //sql_statements[0]->Create_str();
    }

    void Parser::ParseCreateTableStatement(NewLexer& lexer)
    {
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
            /* code */
        }
        sql_statements[0]->Create_str();
    }

    void Parser::ParseSelectTableStatement(NewLexer& lexer)
    {
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
            /* code */
        }
        //sql_statements[4]->Create_str();
    }

    void Parser::ParseInsertTableStatement(NewLexer& lexer)
    {
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
            /* code */
        }
        sql_statements[1]->Create_str();
    }

    void Parser::ParseDeleteTableStatement(NewLexer& lexer)
    {
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
            /* code */
        }
        //sql_statements[4]->Create_str();
    }

    void Parser::run_parse(std::string_view str)
    {
        sql::NewLexer lexer(str);
        Token token;
        do
        {
            token = lexer.PeekToken();
            if (token.Type == TokenType::Keyword && token.Lexem == "CREATE")
            {
                //идем в create
            }
            else if (token.Type == TokenType::Keyword && token.Lexem == "SELECT")
            {
                /* code */
            }
            else if (token.Type == TokenType::Keyword && token.Lexem == "INSERT")
            {
                /* code */
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
                /* code */
            }
            

        } while (token.Type != TokenType::FinalToken);
    }
    Parser::~Parser()
    {
    }
}
