#include <iostream>
#include <lexor.hpp>
#include <CLI.hpp>
#include <string>
#include <NewLexer.hpp>

int main()
{
    std::cout << "Write sql inquiry" << '\n';
    std::string sql_inquiry;
    std::getline(std::cin, sql_inquiry);
    sql::NewLexer lexer(sql_inquiry);
    //std::cout << lexer.GetToken() << std::endl;
    //std::cout << lexer.GetToken() << std::endl;
    return 0;
}
