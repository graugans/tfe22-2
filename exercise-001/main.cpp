#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"


int count = 20;

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};

    
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c, --count", count, fmt::format("The amount of elements in our vector default: {}", count));
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
    fmt::print("value of count: {}!\n", count);

std::vector <int> vector;

    for (int i=0; i<count; ++i) {
        vector.push_back(rand()%100+1); 
    }


    std::sort(vector.rbegin(), vector.rend());

    for (int m = 0; m < vector.size(); m++)
    {
        std::cout << vector[m] << std::endl;
    }
    

 
    

    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
}
