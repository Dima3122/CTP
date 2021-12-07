#include <iostream>
#include <string>
#include <NewLexer.hpp>
#include <Parser.hpp>

int main()
{
    // std::string sql_inquiry = "CREATE TABLE gamer ( name TEXT, age INT , coin REAL );DROP TABLE users";
    std::string sql_inquiry = "SELECT TABLE gamer2 ( name TEXT, age INT );";
    // std::string sql_inquiry = "DELETE TABLE gamer3 ( name TEXT, age INT );";
    // std::string sql_inquiry = "INSERT TABLE gamer ( name TEXT, age INT );";
    SqlScript SqlScript = run_parse(sql_inquiry);
    SqlScript.Statements[0]->get_data();
    // SqlScript.Statements[1]->get_data();
    return 0;
}
