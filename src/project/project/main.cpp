#include <iostream>
#include <string>
#include <Lexer.hpp>
#include <Parser.hpp>
#include <ExecuteVisitor.hpp>
#include <Visitor.hpp>
#include <fstream>

int main()
{
    std::ifstream fin("users.db");
    if (!fin.is_open())
    {
        std::cout << "Ошибка открытия файла!" << std::endl;
        return -1;
    }
    sql::ExecuteVisitor visit;
    std::string sql_inquiry;
    char ch;
    while (fin.get(ch))
    {
        sql_inquiry += ch;
    }
    fin.close();
    SqlScript SqlScript = run_parse(sql_inquiry); 
    if (SqlScript.Errors.size() != 0)
    {
        for (auto &Script : SqlScript.Statements)
        {
            Script->accept(visit);
        }
    }
    else
    {
        for (auto &error : SqlScript.Errors)
        {
            std::cout <<"Ошибка: ожидалось " << error.expected << " Ошибка " << error.str << " Тип ошибки " << error.type << std::endl;
        }
    }
    
    return 0;
}
