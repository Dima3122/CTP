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
    protected:
        std::string TableName;
    public:
        virtual void Write_Data() = 0;
        virtual ~SqlStatement() = default;

        const std::string& Get_TableName() const
        {
            return TableName;
        }
        void Set_TableName(std::string_view str)
        {
            TableName = str;
        }
        virtual void Accept(ExecuteVisitor &visitor) = 0;
    };    
}