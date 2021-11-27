#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <memory>

namespace sql
{
    class LexError : std::exception
    {
    public:
        LexError(std::string _msg) : msg(_msg) {}
        ~LexError() throw() {} // Updated
        const char *what() const throw() { return msg.c_str(); }

    private:
        std::string msg;
    };
 
    class SqlStatement
    {
    protected:
        std::vector<SqlStatement*> sql_statements;
    public:
        virtual ~SqlStatement(){};
    };
}