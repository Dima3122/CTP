#pragma once
#include <string>
#include <iostream>
#include <vector>

namespace sql
{
    struct ColumnDef
    {
        std::string ColumnName;
        std::string TypeName;
    };
    class SqlStatement
    {
    public:
        virtual void get_data() = 0;
        virtual ~SqlStatement() = default;
    };
}