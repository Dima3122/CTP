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
        else
        {//РАЗОБРАТЬСЯ С БАЗОВЫМ КЛАССОМ, что бы все было доступно из SqlStatements!!!!
            if (Tokens[0].Lexem == "CREATE")
            {
                // get_second_token_from();
                // Checking_the_Value_For_Insert();
                // if (error == false)
                // {
                //     sql::CreateTableStatement a;
                //     std::string result = a.Create_Statement(second_token, TypeName, First_Value, (count_argument/2));
                //     std::cout << result << std::endl;
                // }
                // else
                // {
                //     std::cout << "Работа программы завершена" << '\n';
                // }
            }
            else if (Tokens[0].Lexem == "SELECT")
            {
                //послать запрос
            }
            else if (Tokens[0].Lexem == "INSERT")
            {
                // get_second_token_from();
                // Get_Values();
                // if (error == false)
                // {
                //     sql::InsertStatement IS(second_token, Second_Values, First_Value);
                //     std::string result = IS.insert_command();
                //     std::cout << result << std::endl;
                // }
                // else
                // {
                //     std::cout << "Работа программы завершена" << '\n';
                // }
            }
            else if (Tokens[0].Lexem == "DELETE")
            {
                //послать запрос
            }
            else if (Tokens[0].Lexem == "DROP")
            {
                //послать запрос
            }
        }
    }

    Parser::~Parser()
    {
    }
}