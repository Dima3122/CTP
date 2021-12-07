#include "DropTableStatement.hpp"

namespace sql
{  
    DropTableStatement::DropTableStatement()
    {
        
    }
    void DropTableStatement::get_data()
    {
        std::cout << "TableName " << TableName << std::endl;
    }
    void DropTableStatement::set_TableName(std::string_view TableName)
    {
        this->TableName = TableName;
    }
}