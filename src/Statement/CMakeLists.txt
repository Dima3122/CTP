project(Library)
add_library(Statements STATIC lib/CreateTableStatement.cpp lib/SelectStatement.cpp 
            lib/InsertStatement.cpp lib/DropTableStatement.cpp
            lib/DeleteStatement.cpp lib/ExecuteVisitor.cpp 
            lib/MemoryMapped.cpp lib/File.cpp lib/Lexer.cpp lib/Parser.cpp)
set_compile_options(Statements)