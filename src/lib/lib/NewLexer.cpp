#include "NewLexer.hpp"

namespace sql
{
    NewLexer::NewLexer(std::string parse_str)
    {
        this->parse_str = parse_str;
        pos_curs = 0;
        //инициализурем вектор
        rule.push_back(std::regex("\\w{3,10}"));
        //придумать правила....
    }

    NewLexer::~NewLexer()
    {
    }
    //ДОДУМАТЬ!!!!!!!!!!
    std::string NewLexer::GetToken()
    {
        std::smatch matches;
        //продумать как это будет работать с множеством команд и токенов..
        if(std::regex_search(parse_str, matches, rule[0]))
        {        //каждый раз новое правило
            std::string str = matches.str(pos_curs);
            pos_curs++;
            return str;
        }
        else
        {
            return "Токены кончились";
        }
    }

    std::string NewLexer::PeekToken()
    {
        std::smatch matches;
        std::regex_search(parse_str, matches, rule[pos_curs]);
        //взять нужное....
        return matches.str(0);;
    }

}
