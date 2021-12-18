#pragma once
#include <vector>
#include <regex>
#include <iostream>
#include <string>

namespace sql
{
    enum class TokenType
    {
        String,
        Int,
        Real,
        Keyword,
        ID,
        Operation,
        CommonSeparator,
        Bracket,
        Semicolon,
        InvalidToken,
        FinalToken,
        Comma,
        TypeName 
    };

    struct Token
    {
        TokenType Type = TokenType::InvalidToken;
        std::string_view Lexem = "";
    };

    class Lexer
    {
    private:
        struct Rule
        {
            std::regex Regex;
            TokenType Type;
        };
        constexpr static Token FinalToken = {TokenType::FinalToken, ""};
        std::vector<Rule> Rules;    //свод правил (достать тот или иной токен)
        std::string_view parse_str; //строка которую парсим
        size_t pos_curs;

    public:
        Token GetToken();  //передается вся строка, но... по позиии
        Token PeekToken(); //курсора смотрим какое слово надо взять???
        const char *GetTokenTypeName(TokenType type);
        Lexer(std::string_view parse_str);
        ~Lexer();

        void set_parse_str(std::string_view parse_str);
        
    };
}