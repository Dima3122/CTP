#include <iostream>
#include <string>
#include <fstream>
#include <lib/Lexer.hpp>
#include <lib/Parser.hpp>
#include <lib/ExecuteVisitor.hpp>
#include <lib/Visitor.hpp>

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
    sql::SqlScript SqlScript = sql::Parse_str(sql_inquiry); 
    if (SqlScript.Errors.size() != 0)
    {
        for (auto &Script : SqlScript.Statements)
        {
            Script->Accept(visit);
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
