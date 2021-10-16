#include "lexor.hpp"

namespace lexor
{
    Lexical_analyzer::Lexical_analyzer()
    {
        argv = new std::string[10];
        value = new std::string[10];
        TypeName = new std::string[10];
        count_argument = 0;
        error = false;
    }

    void Lexical_analyzer::parse_sql(std::string script_text)
    {
        Break_words(script_text);//Разбиение на токены?
        if(Checking_the_first_operation() == false)
        {
            std::cout << "Выбрано не верное действие"<< '\n';
            error = true;
        }
        else if(Checking_count_argv())
        {
            std::cout << "Не верное количество аргументов"<< '\n';
            error = true;
        }
        else
        {
            if (first_token == "CREATE")
            {
                get_second_token_from();
                Checking_the_Value();
                if (error == false)
                {
                    sql::CreateTableStatement a;
                    std::string result = a.Create_Statement(second_token, TypeName, value, (count_argument/2));
                    std::cout << result << std::endl;
                }
                else
                {
                    std::cout << "Работа программы завершена" << '\n';
                }
                
            }
            else if(first_token == "SELECT")
            {
                get_second_token_from();//????
                //послать запрос
            }
            else if(first_token == "INSERT")
            {
                get_second_token_from();
                Checking_the_Value();
                //послать запрос
            }
            else if(first_token == "DELETE")
            {
                get_second_token_from();
                //послать запрос
            }
            else if(first_token == "DROP")
            {
                get_second_token_from();
                //послать запрос
            }
        }
    }
    
    void Lexical_analyzer::get_second_token_from()
    {
        second_token = argv[1];
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
        if(argv[0] == "CREATE" || argv[0] == "SELECT" || argv[0] == "INSERT"
        || argv[0] == "DELETE" || argv[0] == "DROP")
        {
            first_token = "CREATE";
            return true;
        }  
        else
        {
            return false;
        }
    }

    bool Lexical_analyzer::Checking_the_Value()
    {
        int j = 0;
        int z = 0;
        if(count_argument <= 1)
        {
            std::cout << "Недостаточно аргументов" << '\n';
            return false;
        }
        for(int i = 2; i <= count_argument; i++)
        {//Четные - выбор типа данных, нечетные значение.
            if((i % 2) == 0)//Четные
            {
                if (argv[i] == "INT")
                {
                    TypeName[j] = argv[i];
                    j++;
                }
                else if (argv[i] == "TEXT")
                {
                    TypeName[j] = argv[i];
                    j++;
                }
                else if (argv[i] == "REAL")
                {
                    TypeName[j] = argv[i];
                    j++;
                }
                else
                {
                    error = true;
                    std::cout << "Не правильно выбран тип данных" << '\n';
                }
            }
            else if(i % 2 == 1)//нечетные
            {
                value[z] = argv[i];
                z++;
            }
        }
        return true;
    }

    bool Lexical_analyzer::Checking_count_argv()
    {
        if(count_argument % 2 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }

    void Lexical_analyzer::set_second_token(std::string second_token)
    {
        this->second_token = second_token;
    }
    std::string Lexical_analyzer::get_second_token()
    {
        return second_token;
    }
    void Lexical_analyzer::set_fisttoken(std::string first_token)
    {
        this->first_token = first_token;
    }
    std::string Lexical_analyzer::get_first_token()
    {
        return first_token;
    }
    void Lexical_analyzer::set_count_argument(int count_argument)
    {
        this->count_argument = count_argument;
    }
    int Lexical_analyzer::get_count_argument()
    {
        return count_argument;
    }
    void Lexical_analyzer::set_value(std::string *value)
    {
        this->value = value;
    }
    void Lexical_analyzer::set_TypeName(std::string *TypeName)
    {
        this->TypeName = TypeName;
    }
    void Lexical_analyzer::ser_argv(std::string *argv)
    {
        this->argv = argv;
    }
    std::string *Lexical_analyzer::get_value()
    {
        return value;
    }
    std::string *Lexical_analyzer::get_TypeName()
    {
        return TypeName;
    }
    std::string *Lexical_analyzer::get_argv()
    {
        return argv;
    }
}