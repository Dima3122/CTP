project(Library)
set(CMAKE_CXX_STANDARD 20)
add_library(Statements STATIC lib/Lexer.cpp lib/Parser.cpp lib/SelectStatement.cpp lib/InsertStatement.cpp lib/DropTableStatement.cpp lib/DeleteStatement.cpp lib/CreateTableStatement.cpp lib/ExecuteVisitor.cpp lib/MemoryMapped.cpp lib/File.cpp)
