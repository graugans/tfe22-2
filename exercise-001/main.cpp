#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"
#include "vector"
#include "random"

auto printvector(std::vector<int>& numbers)->void;

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
        app.add_option("-c,--count", count, "A count integer");
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }
   
    std::vector<int> numbers;

    for(int i = 0; i<count; i++){
        numbers.push_back(rand() % 100);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());
    printvector(numbers);
    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
}
auto printvector(std::vector<int>& numbers)-> void{
    for(auto& i : numbers){
        fmt::print("{}\n", i);
    }
}