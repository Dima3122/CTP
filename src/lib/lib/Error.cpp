#include <iostream>
#include <string>

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

}