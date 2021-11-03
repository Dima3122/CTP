#include "NewLexer.hpp"

namespace sql
{
    NewLexer::NewLexer(std::string parse_str)
    {
        this->parse_str = parse_str;
        pos_curs = 0;
        //инициализурем вектор
        Rules = 
        {
            {std::regex("\".*?\"",std::regex_constants::icase), TokenType::String},
            {std::regex("[-+]?0|[-+]?[1-9][0-9]*",std::regex_constants::icase), TokenType::Int},
            {std::regex("[-+]?0.[0-9]+|[1-9][0-9]*.[0-9]*",std::regex_constants::icase), TokenType::Real},
            {std::regex("(SELECT|CREATE|INSERT|DELETE|DROP|FROM|TABLE|INTO|WHERE|VALUES)(?=\\W)",
            std::regex_constants::icase), TokenType::Keyword},
            {std::regex("[a-z][a-z0-9]*",std::regex_constants::icase), TokenType::ID},
            {std::regex("=|!=|<|>|>=|=<",std::regex_constants::icase), TokenType::Operation},
            {std::regex("\t|\r|\n|\\s|$",std::regex_constants::icase), TokenType::CommonSeparation},
            {std::regex("[\\{\\}\\(\\)]",std::regex_constants::icase), TokenType::Bracket},
            {std::regex(";",std::regex_constants::icase), TokenType::Semicolom},
        };
    }

    NewLexer::~NewLexer()
    {
    }

    std::ofstream& operator<<(std::ofstream& os, const Token& Token)
    {
        std::cout << "Lexem:" << Token.Lexem << "\n";
        return os;
    }

    Token NewLexer::GetToken()
    {
        std::smatch matches;
        auto token = PeekToken();
        pos_curs += token.Lexem.size();
        return token;
    }

    Token NewLexer::PeekToken()
    {
        if(pos_curs >= parse_str.size())
        {
            return NewLexer::FinalToken;
        }
        for (auto&& it : Rules)
        {
            std::cmatch match;
            if(std::regex_search(parse_str.data() + pos_curs, match, it.Regex,std::regex_constants::match_continuous))
            {
                return {it.Type, std::string_view(parse_str.data() + pos_curs, match.begin()->length())};
            }
        }
    }
}