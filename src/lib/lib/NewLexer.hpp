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
        CommonSeparation,
        Bracket,
        Semicolom,
        InvalidToken,
        FinalToken
    };

    struct Token
    {
        TokenType Type = TokenType::InvalidToken;
        std::string_view Lexem = "";
    };
    

    class NewLexer
    {
    private:
        struct Rule
        {
            std::regex Regex;
            TokenType Type;
        };
        constexpr static Token FinalToken = {TokenType::FinalToken, ""};
        std::vector<Rule> Rules; //свод правил (достать тот или иной токен)
        std::string_view parse_str;   //строка которую парсим
        size_t pos_curs;

    public:
        Token GetToken();  //передается вся строка, но... по позиии
        Token PeekToken(); //курсора смотрим какое слово надо взять???
        NewLexer(std::string parse_str);
        ~NewLexer();
    };
}