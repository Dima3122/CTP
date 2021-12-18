#pragma once
#include <iostream>

namespace sql
{
    class MemoryMappedFile
    {
    private:
        // ...
    public:
        // explicit MemoryMappedFile(const std::filesystem::path &path);
        ~MemoryMappedFile() = default;

        // TODO: подумайте, как должны быть определены:
        //  - move constructor
        //  - copy constructor
        //  - copy assignment
        //  - move assignment

        void *data() const;

    };
}