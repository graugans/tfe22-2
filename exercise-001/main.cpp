#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h.in"

#include <vector>
#include <random>
#include <iostream>

void print_vector(const std::vector<int>& counter_v)
{
    fmt::print("Vector: {}\n", fmt::join(counter_v, ", "));
}

void sort_vector(const std::vector<int>& counter_v)
{
    fmt::print("Sorted Vector: {}\n", fmt::join(counter_v, ", "));
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
        app.add_option("-c,--count", count, "set count:") -> check(CLI::Range(0,100));
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
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
    fmt::print("count: {}\n", count);

    srand(time(0));

    std::vector<int> counter_v(count);

    for(auto & val : counter_v)
    {
        val = rand() % 100+ 1;
    } 

    std::sort(counter_v.begin(), counter_v.end());

    print_vector(counter_v);
    sort_vector(counter_v);

    return 0; /* exit gracefully*/
}
