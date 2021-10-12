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
            std::string first_token;
            std::string second_token;
            int count_argument;
            bool error;


            void Break_words(std::string TableName);
            bool Checking_the_first_operation();
            bool Checking_the_Value();
        public:
            void parse_sql(std::string script_text);
            Lexical_analyzer();
    };      
}