#pragma once
#include <vector>
#include <regex>
#include <iostream>

namespace sql
{
    class NewLexer
    {
    private:
        std::vector<std::regex> rule;//свод правил (достать тот или иной токен)
        std::string parse_str;//строка которую парсим
        size_t pos_curs;
    public:
        std::string GetToken();//передается вся строка, но... по позиии
        std::string PeekToken();//курсора смотрим какое слово надо взять???
        NewLexer(std::string parse_str);
        ~NewLexer();
    };
}