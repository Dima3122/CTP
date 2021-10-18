#include "lexor.hpp"

namespace lexor
{
    Lexical_analyzer::Lexical_analyzer(int size)
    {
        argv = new std::string[size];
        First_Value = new std::string[size];
        TypeName = new std::string[size];
        Second_Values = new std::string[size];
        Script_Comands = new std::string[size];
        count_argument = 0;
        count_commands = 0;
        error = false;
    }

    void Lexical_analyzer::parse_sql(std::string script_text)
    {
        //TODO: несколько запросов в одной строке.
        //TODO: Очень сильно доработать ошибочки (Где конректно не верно)
        Break_str_on_delim(script_text, ";");//Разбиение на токены?
        count_commands = count_argument;
        for (int i = 0; i < count_commands; i++)
        {
            Script_Comands[i] = argv[i];
        }
        
        for (int i = 0; i < count_commands; i++)
        {
            Break_str_on_delim(Script_Comands[i], " ");//Разбиение на токены?
            if(Checking_the_first_operation() == false)
            {
                std::cout << "Выбрано не верное действие"<< '\n';
                error = true;
            }
            if(Checking_count_argv())
            {
                std::cout << "Не верное количество аргументов"<< '\n';
                error = true;
            }
            else
            {
                if (first_token == "CREATE")
                {
                    get_second_token_from();
                    Checking_the_Value_For_Insert();
                    if (error == false)
                    {
                        sql::CreateTableStatement a;
                        std::string result = a.Create_Statement(second_token, TypeName, First_Value, (count_argument/2));
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
                    Get_Values();
                    if (error == false)
                    {
                        sql::InsertStatement IS(second_token, Second_Values, First_Value);
                        std::string result = IS.insert_command();
                        std::cout << result << std::endl;
                    }
                    else
                    {
                        std::cout << "Работа программы завершена" << '\n';
                    }
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
            //обнуление переменных
        }
        
    }
    
    void Lexical_analyzer::get_second_token_from()
    {
        second_token = argv[1];
    }
    
    void Lexical_analyzer::Break_str_on_delim(std::string script_text,
    std::string delimiter)
    {
        std::string s = script_text;
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
            first_token = argv[0];
            return true;
        }  
        else
        {
            return false;
        }
    }

    void Lexical_analyzer::Get_Values()
    {
        int j = 0;
        int z = 0;
        if(count_argument <= 1)
        {
            std::cout << "Недостаточно аргументов" << '\n';
            error = true;
        }
        for(int i = 2; i <= count_argument; i++)
        {//Четные - выбор типа данных, нечетные значение.
            if((i % 2) == 0)//Четные
            {
                Second_Values[j] = argv[i];
                j++;
            }
            else if(i % 2 == 1)//нечетные
            {
                First_Value[z] = argv[i];
                z++;
            }
        }
    }

    void Lexical_analyzer::Checking_the_Value_For_Insert()
    {
        int j = 0;
        int z = 0;
        if(count_argument <= 1)
        {
            std::cout << "Недостаточно аргументов" << '\n';
            error = true;
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
                First_Value[z] = argv[i];
                z++;
            }
        }
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
    void Lexical_analyzer::set_First_Value(std::string *First_Value)
    {
        this->First_Value = First_Value;
    }
    void Lexical_analyzer::set_TypeName(std::string *TypeName)
    {
        this->TypeName = TypeName;
    }
    void Lexical_analyzer::set_argv(std::string *argv)
    {
        this->argv = argv;
    }
    std::string *Lexical_analyzer::get_First_Value()
    {
        return First_Value;
    }
    std::string *Lexical_analyzer::get_TypeName()
    {
        return TypeName;
    }
    std::string *Lexical_analyzer::get_argv()
    {
        return argv;
    }
    void Lexical_analyzer::set_Second_Values(std::string *Second_Values)
    {
        this->Second_Values = Second_Values;
    }
    std::string *Lexical_analyzer::get_Second_Values()
    {
        return Second_Values;
    }
    int Lexical_analyzer::get_count_commands()
    {
        return count_commands;
    }
    void Lexical_analyzer::set_count_commands(int count_commands)
    {
        this->count_commands = count_commands;
    }
}