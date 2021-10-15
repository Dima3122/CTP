#pragma once
#include <string>
#include <iostream>

namespace lexor
{
    class Lexical_analyzer
    {
        private:
            std::string *argv;//распарсенная строка по пробелам
            std::string *value;//значение
            std::string *TypeName;//тип значения
            std::string second_token;//аргумент для отдельных операций
            std::string first_token;//операция
            int count_argument;//количество аргументов
            bool error;//есть ли лексические ошибки
            //выбор действия, аргументы
            void Break_words(std::string TableName);//разбиваем на токены
            void get_second_token_from();//получить аргумент для отдельных операций
            bool Checking_the_first_operation();//проверка операции
            bool Checking_the_Value();//проверка значений
        public:
            void parse_sql(std::string script_text);//начало парсинга
            Lexical_analyzer();//конструктор
            //думаю что и так понятно=)
            void set_second_token(std::string second_token);
            void set_fisttoken(std::string first_token);
            void set_count_argument(int count_argument);
            void set_value(std::string *value);
            void set_TypeName(std::string *TypeName);
            void ser_argv(std::string *argv);

            std::string get_second_token();
            std::string get_first_token();
            std::string *get_value();
            std::string *get_TypeName();
            std::string *get_argv();
            int get_count_argument();
    };      
}