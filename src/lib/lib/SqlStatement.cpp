#include <string>
#include <iostream>
#include <vector>

namespace sql
{
    class SqlStatement
    {
    private:
        //std::vector<LexError> errors_;
        std::vector<SqlStatement> sql_statements_;
    public:
        virtual ~SqlStatement(){};
    };
}