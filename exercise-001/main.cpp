#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

#include "vector"
#include "time.h"

auto print_vector(std::vector<int> &Zufallsvektor) -> void
    {
        for(auto value: Zufallsvektor){
            fmt::print("{}\n", value);
        }
    }

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    int count = 20;
    srand(time(NULL));

    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count", count, "Eingabe des Parameters.");
        app.parse(argc, argv);
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
    fmt::print("Counter: {}\n", count);

    /* INSERT YOUR CODE HERE */
    std::vector <int> Zufallsvektor(count);

    for(int i = 0; i < count; i++){
        Zufallsvektor.at(i) = (rand() % 100) + 1;
    }
    print_vector(Zufallsvektor);

    fmt::print("Geordnet:\n");

    std::sort(Zufallsvektor.begin(),Zufallsvektor.end());
    print_vector(Zufallsvektor);

    return 0; /* exit gracefully*/
}
