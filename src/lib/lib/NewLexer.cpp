#include "NewLexer.hpp"

namespace sql
{
    NewLexer::NewLexer(std::string_view parse_str)
    {
        this->parse_str = parse_str;
        pos_curs = 0;
        //инициализурем вектор
        Rules =
            {
                //std::regex_constants::icase Сопоставление символов должно выполняться без учета регистра.
                {std::regex("\".*?\"", std::regex_constants::icase), TokenType::String},
                {std::regex("[-+]?0|[-+]?[1-9][0-9]*", std::regex_constants::icase), TokenType::Int},
                {std::regex("[-+]?0.[0-9]+|[1-9][0-9]*.[0-9]*", std::regex_constants::icase), TokenType::Real},
                {std::regex("(SELECT|CREATE|INSERT|DELETE|DROP|FROM|TABLE|INTO|WHERE|VALUES)(?=\\W)",
                            std::regex_constants::icase),
                 TokenType::Keyword},
                {std::regex("[a-z][a-z0-9]*", std::regex_constants::icase), TokenType::ID},
                {std::regex("=|!=|<|>|>=|=<", std::regex_constants::icase), TokenType::Operation},
                {std::regex("\t|\r|\n|\\s|$", std::regex_constants::icase), TokenType::CommonSeparator},
                {std::regex("[\\{\\}\\(\\)]", std::regex_constants::icase), TokenType::Bracket},
                {std::regex(";", std::regex_constants::icase), TokenType::Semicolon},
            };
    }

    NewLexer::~NewLexer()
    {
    }

    std::ofstream &operator<<(std::ofstream &os, const Token &Token)
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

    void NewLexer::set_parse_str(std::string_view parse_str)
    {
        this->parse_str = parse_str;
    }

    Token NewLexer::PeekToken()
    {
        if (pos_curs >= parse_str.size())
        {
            return NewLexer::FinalToken;
        }
        for (auto &&it : Rules)
        {                      //поиск по строке в поисках подстрок, которые regex совпадения, regex_search
            std::cmatch match; //Это экземпляр шаблона класса match_results для совпадений в строковых литералах
            if (std::regex_search(parse_str.data() + pos_curs, match, it.Regex, std::regex_constants::match_continuous))
            { //data() возвращает указатель на данные без каких-либо изменений.
                return {it.Type, std::string_view(parse_str.data() + pos_curs, match.begin()->length())};
            }
        }
        return Token();
    }

    const char *NewLexer::GetTokenTypeName(TokenType type)
    {
        switch (type)
        {
        case TokenType::String:
            return "String";
        case TokenType::FinalToken:
            return "FinalToken";
        case TokenType::InvalidToken:
            return "InvalidToken";
        case TokenType::ID:
            return "ID";
        case TokenType::Real:
            return "Real";
        case TokenType::Int:
            return "Int";
        case TokenType::Keyword:
            return "Keyword";
        case TokenType::Operation:
            return "Operation";
        case TokenType::CommonSeparator:
            return "CommonSeparator";
        case TokenType::Bracket:
            return "Bracket";
        case TokenType::Semicolon:
            return "Semicolon";
        }
        return "Unknown";
    }
}