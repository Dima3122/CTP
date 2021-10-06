#include <iostream>
#include "../lib/lib/calc.hpp"
#include "../../../external/cli11/include/CLI/CLI.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    CLI::App app{"App description"};

    float first = 0.f;
    app.add_option("-f,--first", first, "Set first argument")->required();
    
    float second = 0.f;
    app.add_option("-s,--second", second, "Set second argument")->required();
    CLI11_PARSE(app, argc, argv);

    cout << SumTwoFloat(first, second) << "\n";
    return 0;
}
