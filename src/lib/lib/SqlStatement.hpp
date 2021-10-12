#pragma once
#include <string>
#include <iostream>
namespace sql
{
    class SqlStatement
    {
        public:
            virtual ~SqlStatement() = 0;
    };
}