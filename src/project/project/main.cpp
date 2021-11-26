#include <iostream>
#include <CLI.hpp>
#include <string>
#include <NewLexer.hpp>

int main()
{
    std::cout << "Write sql inquiry" << '\n';
    std::string sql_inquiry;
    std::getline(std::cin, sql_inquiry);
    sql::NewLexer lexer(sql_inquiry);
    sql::Token a = lexer.GetToken();
    std::cout << a.Lexem  << " "<< lexer.GetTokenTypeName(a.Type) <<std::endl;
    a = lexer.GetToken();
    std::cout << a.Lexem << " "<< lexer.GetTokenTypeName(a.Type) <<std::endl;
    a = lexer.GetToken();
    std::cout << a.Lexem << " "<< lexer.GetTokenTypeName(a.Type) <<std::endl;    
    a = lexer.GetToken();
    std::cout << a.Lexem << " "<< lexer.GetTokenTypeName(a.Type) <<std::endl;
    a = lexer.GetToken();
    std::cout << a.Lexem << " "<< lexer.GetTokenTypeName(a.Type) <<std::endl;
    a = lexer.GetToken();
    std::cout << a.Lexem << " "<< std::endl;
    a = lexer.GetToken();
    std::cout << a.Lexem << " "<< std::endl;
    a = lexer.GetToken();
    std::cout << a.Lexem << std::endl;
    //std::cout << lexer.GetToken() << std::endl;
    return 0;
}
