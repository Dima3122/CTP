#include <iostream>
#include <string>
#include <NewLexer.hpp>
#include <SelectStatement.hpp>
#include <CreateTableStatement.hpp>
#include <SqlStatement.hpp>
#include <InsertStatement.hpp>
#include <DeleteStatement.hpp>
#include <DropTableStatement.hpp>
#include "Parser.hpp"
int main()
{
    std::cout << "Write sql inquiry" << '\n';
    std::string sql_inquiry;
    std::getline(std::cin, sql_inquiry);
    SqlScript a = run_parse(sql_inquiry);
    //pars.run_parse(sql_inquiry, sql_statements);
    //sql::NewLexer lexer(sql_inquiry);
    // sql::Token a = lexer.GetToken();
    // std::cout << a.Lexem  << " "<< lexer.GetTokenTypeName(a.Type) <<std::endl;
    // a = lexer.GetToken();
    // std::cout << a.Lexem << " "<< lexer.GetTokenTypeName(a.Type) <<std::endl;
    // a = lexer.GetToken();
    // std::cout << a.Lexem << " "<< lexer.GetTokenTypeName(a.Type) <<std::endl;
    // a = lexer.GetToken();
    // std::cout << a.Lexem << " "<< lexer.GetTokenTypeName(a.Type) <<std::endl;
    // a = lexer.GetToken();
    // std::cout << a.Lexem << " "<< lexer.GetTokenTypeName(a.Type) <<std::endl;
    // a = lexer.GetToken();
    // std::cout << a.Lexem << " "<< std::endl;
    // a = lexer.GetToken();
    // std::cout << a.Lexem << " "<< std::endl;
    // a = lexer.GetToken();
    // std::cout << a.Lexem << std::endl;
    return 0;
}
