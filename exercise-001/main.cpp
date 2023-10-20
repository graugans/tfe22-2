#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

void print_vector(const std::vector<int>& vec);

auto main(int argc, char **argv) -> int
{
    auto count{20};
    auto count = 20;

    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */

    CLI::App app{PROJECT_NAME};
    try
    {
        app.add_option("-c, --count", count, "set count:") ->check(CLI::Range(0, 100));
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count",count,fmt::format("The amount of elements in our vector default: {}",count));
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

    /* INSERT YOUR CODE HERE */

    srand(time(0));

    std::vector<int> random_vector(count); 

    for(auto & val : random_vector)         //filling vector with random values
    {
        val = rand() % 100 + 1;
    }

    print_vector(random_vector);

    return 0; /* exit gracefully*/
}


void print_vector(const std::vector<int>& vec) {
    for(const int& val : vec) {
        fmt::print("{} ", val);
    }
    std::cout << '\n';
}