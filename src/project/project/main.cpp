#include <iostream>
#include <string>
#include <Lexer.hpp>
#include <Parser.hpp>
#include <ExecuteVisitor.hpp>
#include <Visitor.hpp>

int main()
{
    std::string sql_inquiry = "CREATE TABLE gamer ( name TEXT, age INT , coin REAL );DROP TABLE users";
    // std::string sql_inquiry = "SELECT TABLE gamer ( name TEXT name , age INT name );";
    // std::string sql_inquiry = "DELETE TABLE gamer3 ( name TEXT name , age INT name );";
    // std::string sql_inquiry = "INSERT TABLE gamer ( name TEXT, age INT );";
    sql::ExecuteVisitor visit;
    SqlScript SqlScript = run_parse(sql_inquiry);
    SqlScript.Statements[0]->write_data();
    SqlScript.Statements[1]->write_data();
    // SqlScript.Statements[0]->accept(visit);
    // SqlScript.Statements[0]->accept();
    return 0;
}
