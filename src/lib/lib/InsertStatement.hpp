#pragma once
#include "SqlStatement.hpp"

namespace sql
{
    class InsertStatement : public SqlStatement
    {
    private:
        std::string table_name;
        std::string *column_names;
        std::string *values;

    public:
        InsertStatement(std::string table_name, std::string *column_names, std::string *values);
        InsertStatement();
        void set_table_name(std::string table_name);
        void set_column_names(std::string *column_names);
        void set_values(std::string *values);
        std::string get_table_name();
        std::string *get_column_names();
        std::string *get_values();
        std::string insert_command();
        ~InsertStatement();
        void Create_str() override;
    };
}