#include "NewLexer.hpp"

namespace sql
{
    NewLexer::NewLexer(std::string parse_str)
    {
        this->parse_str = parse_str;
        pos_curs = 0;
        //инициализурем вектор
        rule = "CREATE";
        //придумать правила....
    }

    NewLexer::~NewLexer()
    {
    }

    std::string NewLexer::GetToken()
    {
        std::smatch matches;
        std::regex_search(parse_str, matches, rule);
        //взять нужное....
        return matches.str(0);
    }

    std::string NewLexer::PeekToken()
    {
        std::smatch matches;
        std::regex_search(parse_str, matches, rule);
        //взять нужное....
        return matches.str(0);;
    }

}
