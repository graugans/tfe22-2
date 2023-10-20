#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h.in"

#include <vector>
#include <random>
#include <iostream>

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

    std::vector<int> counter(count);
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,100);

    int i = 0;
    for(i = 0; i <= count; i++)
    {
        counter.push_back(distribution(generator));
    }

    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
}
