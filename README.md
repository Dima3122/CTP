# CTP
# После загрузки репозитория
git submodule init 
git submodule update
# Конфигурация
cmake -S . -B build/Debug -DCMAKE_BUILD_TYPE=Debug
# Сборка
cmake --build build/Debug