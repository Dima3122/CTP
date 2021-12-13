#include <iostream>
#include <fstream>

namespace sql
{
    class File
    {
    private:
        std::ifstream fin;
        std::string file_name;
    public:
        File(std::string filename);
        ~File();

        std::string read_on_file();
        void write_on_file(std::string str); 
    };
}