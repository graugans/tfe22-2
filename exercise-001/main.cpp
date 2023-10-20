#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */

    auto start = std::chrono::system_clock::now();
    
    CLI::App app{PROJECT_NAME};

    auto count {20};

    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c", count, "count");
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

    std::vector<int> vector;

    srand(time(NULL));
    for (int i = 0; i < count; i++)
    {
        vector.push_back(1 + rand() % 100);
    }

    for (int n : vector)
        fmt::print("{}, ", n);
    fmt::print("\n");

    std::sort(vector.begin(), vector.end());

    for (int n : vector)
        fmt::print("{}, ", n);
    fmt::print("\n");

    auto end = std::chrono::system_clock::now();
    auto elapsed = end - start;
    fmt::print("elapsed {}", elapsed);

    return 0; /* exit gracefully*/
}
