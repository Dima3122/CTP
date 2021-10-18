#pragma once
#include <string>
#include <iostream>
#include "CreateTableStatement.hpp"
#include "InsertStatement.hpp"
namespace lexor
{
    class Lexical_analyzer
    {
        private:
            std::string *Script_Comands;
            std::string *argv;//распарсенная строка по пробелам
            std::string *First_Value;//значение
            std::string *TypeName;//тип значения
            std::string *Second_Values;
            std::string second_token;//аргумент для отдельных операций
            std::string first_token;//операция
            int count_commands;
            int count_argument;//количество аргументов
            bool error;//есть ли лексические ошибки
            //выбор действия, аргументы
            void Break_str_on_delim(std::string TableName, std::string delimeter);//разбиваем на токены
            void get_second_token_from();//получить аргумент для отдельных операций
            bool Checking_the_first_operation();//проверка операции
            void Checking_the_Value_For_Insert();//проверка значений
            void Get_Values();//Получить значения в First_Value и Second_Values
            bool Checking_count_argv();
        public:
            void parse_sql(std::string script_text);//начало парсинга
            Lexical_analyzer(int size);//конструктор
            //думаю что и так понятно=)
            void set_second_token(std::string second_token);
            void set_fisttoken(std::string first_token);
            void set_count_argument(int count_argument);
            void set_First_Value(std::string *First_Value);
            void set_TypeName(std::string *TypeName);
            void set_argv(std::string *argv);
            void set_Second_Values(std::string *Second_Values);
            void set_count_commands(int count_commands);

            std::string get_second_token();
            std::string get_first_token();
            std::string *get_First_Value();
            std::string *get_TypeName();
            std::string *get_argv();
            std::string *get_Second_Values();
            int get_count_argument();
            int get_count_commands();
    };      
}