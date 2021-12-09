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
        
        virtual void set_TableName(std::string_view TableName) = 0;
        virtual void set_colomns(struct ColumnDef a) = 0;
        
        virtual std::string get_TableName() = 0;
        virtual std::vector<ColumnDef> get_colums() = 0;

        virtual void execute(/*rdb::Database& db*/) = 0;
    };
}