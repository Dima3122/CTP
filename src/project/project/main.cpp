#include <iostream>
#include "../lib/lib/calc.hpp"
#include "../../../external/cli11/include/CLI/CLI.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    CLI::App app{"App description"};

    std::string filename = "default";
    app.add_option("-f,--file", filename, "A help string");

    CLI11_PARSE(app, argc, argv);

    cout << sumTwoFloat(11.4, 5.7) << "\n";
    return 0;
}
