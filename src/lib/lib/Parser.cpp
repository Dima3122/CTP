#include "Parser.hpp"

namespace sql
{
    Parser::Parser(std::string sql_inquiry)
    {
        lexer.set_parse_str(sql_inquiry);
        this->sql_inquiry = sql_inquiry;
        Tokens = new Token[100];
    }

    int Parser::get_all_tokens()
    {
        int i = 0;
        Tokens[i] = lexer.GetToken();
        while (Tokens[i].Type != TokenType::FinalToken)
        {
            i++;
            Tokens[i] = lexer.GetToken();
        }
        return i;
    }

    void Parser::run_parse()
    {
        int count_tokens = get_all_tokens();
        if (Tokens[0].Type != TokenType::Operation)
        {
            //кидаем ошибку, вспомнить бы как....
        }
        
    }

    Parser::~Parser()
    {
    }
}