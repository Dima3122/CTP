#include "InsertStatement.hpp"

namespace sql {
bool only_letters(std::string str)
{
    for (int i = 0; i < (int)str.length(); i++) {
        if ('a' > str[i] || str[i] > 'z') {
            if ('A' > str[i] || str[i] > 'Z')
                return false;
        }
    }
    return true;
}

void InsertStatement::Create_str()
{
    
}

InsertStatement::InsertStatement()
{

}

InsertStatement::InsertStatement(std::string table_name, std::string *column_names, std::string *values)
{
    this->table_name = table_name;
    this->column_names = column_names;
    this->values = values;
}
InsertStatement::~InsertStatement()
{
}
void InsertStatement::set_table_name(std::string table_name)
{
    this->table_name = table_name;
}
void InsertStatement::set_column_names(std::string *column_names)
{
    this->column_names = column_names;
}
void InsertStatement::set_values(std::string *values)
{
    this->values = values;
}
std::string InsertStatement::get_table_name()
{
    return this->table_name;
}
std::string *InsertStatement::get_column_names()
{
    return this->column_names;
}
std::string *InsertStatement::get_values()
{
    return this->values;
}
std::string InsertStatement::insert_command()
{
    std::string output;
    std::string *ptr = this->column_names;
    int cn = 2;
    // while (ptr != NULL) {
    //     ptr++, cn++;
    // }
    // ptr = this->values;
    int cv = 2;
    // while (ptr != NULL) {
    //     ptr++, cv++;
    // }
    int size = (cn == cv) ? cn : -1;
    if (size != -1) {
        output += "INSERT INTO " + this->table_name;
        output += " (";
        for (int i = 0; i < size; i++) {
            output += this->column_names[i];
            if (i + 1 != size)
                output += ", ";
        }
        output += ") VALUES (";
        for (int i = 0; i < size; i++) {
            if (only_letters(this->values[i]))
                output += "\"" + this->values[i] + "\"";
            else
                output += this->values[i];
            if (i + 1 != size)
                output += ", ";
        }
        output += ");";
    } else {
        std::cout << "INSERT_STATEMENT: size of column names doesn't equal with size of values\n";
        return NULL;
    }
    return output;
}
}