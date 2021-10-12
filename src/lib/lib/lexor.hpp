#pragma once
#include <string>
#include <iostream>

namespace lexor
{
    class Lexical_analyzer
    {
        public:
            void parse_sql(std::string_view TableName);
    };
}