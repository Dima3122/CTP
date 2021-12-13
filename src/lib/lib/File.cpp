#include "File.hpp"

namespace sql
{
    File::File(std::string filename)
    {
        fin.open(filename);
        if (!fin.is_open())
        {
            std::cout << "Ошибка открытия файла!" << std::endl;
            exit(-1);
        }
        this->file_name = file_name;
    }
    File::~File()
    {
        fin.close();
    }

    std::string File::read_on_file()
    {
        std::string sql_inquiry;
        char ch;
        while (fin.get(ch))
        {
            sql_inquiry += ch;
        }
        return sql_inquiry;
    }

    void File::write_on_file(std::string str)
    {
        std::ofstream fot(file_name);
        fot << str;
    }
}