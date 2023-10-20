#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

 void print_vector(std::vector<int> &zufallszahlen)
{
    for(int zahl : zufallszahlen)
    {
    fmt::print("{} ", zahl);
    }
}

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    
     int count = 20;
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.parse(argc, argv);
        app.add_option("-c,--count",count,"Anzahl festlegen:")->check(CLI::Range(0,100));
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }


    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());

    /* INSERT YOUR CODE HERE */
   
fmt::print("Wert: {}\n",count);

std::vector<int> zufallszahlen;
srand(static_cast<unsigned>(time(nullptr)));

for(int i=0; i<count; i++)
{
    int zufallszahl= rand() % 100 +1;
    zufallszahlen.push_back(zufallszahl);
}

print_vector(zufallszahlen);
fmt::print("\n");
auto start = std::chrono::system_clock::now();
std::sort(zufallszahlen.begin(), zufallszahlen.end());
auto end = std::chrono::system_clock::now();
auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
fmt::print("Time: {}", elapsed);
fmt::print("\n");
print_vector(zufallszahlen);





return 0; 
}


