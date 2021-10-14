#include <iostream>
#include <lexor.hpp>
#include <CLI.hpp>
#include <string>

int main(/*int argc, char *argv[]*/)
{
    //CLI::App app{"App description"};
    //float first = 0.f;
    //app.add_option("-f,--first", first, "Set first argument")->required();
    //float second = 0.f;
    //app.add_option("-s,--second", second, "Set second argument")->required();
    //CLI11_PARSE(app, argc, argv);
    //sql::SqlStatement a;
    //a.CreateTableStatement("hello");
    //std::cout <<  << "\n";
    lexor::Lexical_analyzer lex;
    std::string sql_inquiry;
    std::cout << "Write sql inquiry" << '\n';
    std::getline(std::cin, sql_inquiry);
    lex.parse_sql(sql_inquiry);
    
    return 0;
}
