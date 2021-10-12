#include "lexor.hpp"

namespace lexor
{
    Lexical_analyzer::Lexical_analyzer()
    {
        argv = new std::string[10];
        value = new std::string[10];
        count_argument = 0;
        error = false;
    }

    void Lexical_analyzer::parse_sql(std::string script_text)
    {
        Break_words(script_text);//Разбиение на токены?
        if(Checking_the_first_operation() == false)//засунуть в цикл и разбирать
        {// аргументы, пока они не кончатся
            std::cout << "Выбрано не верное действие"<< '\n';
            error = true;
        }
        // std::cout << count_argument <<std::endl;
        Checking_the_Value();
    }
    
    void Lexical_analyzer::Break_words(std::string script_text)
    {
        
        std::string s = script_text;
        std::string delimiter = " ";
        int i = 0;
        size_t pos = 0;
        std::string token;
        while ((pos = s.find(delimiter)) != std::string::npos) 
        {
            token = s.substr(0, pos);
            s.erase(0, pos + delimiter.length());
            argv[i] = token;
            i++;
        }
        argv[i] = s;
        count_argument = i;
    }

    bool Lexical_analyzer::Checking_the_first_operation()
    {
        if(argv[0] == "CREATE")
        {
            first_token = "CREATE";
            return true;
        }
        else if(argv[0] == "SELECT")
        {
            first_token = "SELECT";
            return true;
        }
        else if(argv[0] == "INSERT")
        {
            first_token = "INSERT";
            return true;
        }
        else if(argv[0] == "DELETE")
        {
            first_token = "DELETE";
            return true;
        }
        else if(argv[0] == "DROP")
        {
            first_token = "DROP";
            return true;
        }
        else
        {
            return false;
        }
    }

    bool Lexical_analyzer::Checking_the_Value()
    {
        if(count_argument <= 1)
        {
            std::cout << "Недостаточно аргументов" << '\n';
            return false;
        }
        for(int i = 1; i <= count_argument; i++)
        {//Четные - выбор типа данных, нечетные значение.
            if((i % 2) == 0)//Четные
            {
                //TODO
            }
            else if(i % 2 == 1)//нечетные
            {
                //TODO
            }
        }
        return true;
    }
}