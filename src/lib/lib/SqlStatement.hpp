#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "ExecuteVisitor.hpp"

namespace sql
{
    struct ColumnDef
    {
        std::string ColumnName;
        std::string TypeName_or_value;
    };
    struct Expression
    {
        std::string Operand1;
        std::string Operation;
        std::string Operand2;
    };
    class SqlStatement
    {
    public:
        virtual void write_data() = 0;
        virtual ~SqlStatement() = default;

        virtual std::string get_TableName() = 0;

        virtual void accept(ExecuteVisitor &visitor) = 0;
    };    
}