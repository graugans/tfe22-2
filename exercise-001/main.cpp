#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

#include <vector>
#include <time.h>
#include <chrono>

auto print_vector(std::vector<int>) -> void;

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    int count = 20;
    srand(time(NULL));

    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count", count, "Enter the number of vectors you want to create");
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
    //fmt::print("Hello, {}!\n", app.get_name());

    /* INSERT YOUR CODE HERE */

    std::vector<int> Zufallsvektor(count);

    for (int i = 0; i < count; i++) {
        Zufallsvektor.at(i) = (rand() % 100) + 1;
    }

    fmt::print("Zufällig:\n");
    print_vector(Zufallsvektor);

    auto start = std::chrono::system_clock::now();
    std::sort(Zufallsvektor.begin(), Zufallsvektor.end());
    auto end = std::chrono::system_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    fmt::print("\nSortiert in {} Nanosekunden:\n", elapsed);
    print_vector(Zufallsvektor);

    return 0; /* exit gracefully*/
}

auto print_vector(std::vector<int> vec) -> void {
    for(auto value : vec) {
        fmt::print("Value: {}\n", value);
    }
}