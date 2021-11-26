#include <string>
#include <iostream>
#include <vector>

namespace sql
{
    class SqlStatement
    {
    private:
        std::vector<SqlStatement*> sql_statements;
    public:
        virtual ~SqlStatement(){};
    };
}