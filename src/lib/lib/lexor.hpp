#pragma once
#include <string>
#include <iostream>

namespace lexor
{
    class Lexical_analyzer
    {
        private:
            std::string *argv;
            std::string *value;
            std::string *TypeName;
            std::string second_token;
            std::string first_token;
            int count_argument;
            bool error;
            //выбор действия, аргументы
            void Break_words(std::string TableName);
            void get_second_token_from();
            bool Checking_the_first_operation();
            bool Checking_the_Value();
        public:
            void parse_sql(std::string script_text);
            Lexical_analyzer();

            void set_second_token(std::string second_token);
            void set_fisttoken(std::string first_token);
            void set_count_argument(int count_argument);

            std::string get_second_token();
            std::string get_first_token();
            int get_count_argument();
    };      
}