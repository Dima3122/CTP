#include <iostream>
#include <SqlStatement.hpp>
#include <CLI.hpp>

int main(int argc, char *argv[])
{
    CLI::App app{"App description"};

    float first = 0.f;
    app.add_option("-f,--first", first, "Set first argument")->required();
    
    float second = 0.f;
    app.add_option("-s,--second", second, "Set second argument")->required();
    CLI11_PARSE(app, argc, argv);
    //sql::SqlStatement a;
    //a.CreateTableStatement("hello");
    //std::cout <<  << "\n";
    return 0;
}
