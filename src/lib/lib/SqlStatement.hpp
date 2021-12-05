#pragma once
#include <string>
#include <iostream>
#include <vector>

namespace sql
{ 
    class SqlStatement
    {
    public:
        virtual ~SqlStatement() = default;
    };
}