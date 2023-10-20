#include <fmt/chrono.h>
#include <fmt/format.h>

#include <time.h>  
#include <vector>
#include "CLI/CLI.hpp"
#include "config.h"

void vector_output(std::vector<int>);

auto main(int argc, char **argv) -> int
{
    srand (time(NULL));
    int count=20;
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c, --count", count, "Enter a count for Number of values in vector");
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

    std::vector<int> zufall_vector(count);
    for(int i=0; i< count;i++)
    {
        zufall_vector.at(i) = rand() % 100 +1;
        //zufall_vector.push_back(rand()%100 +1);
    }
    vector_output(zufall_vector);



    fmt::print("Hello, {}!\n", app.get_name());

    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
}



void vector_output(std::vector<int> neuer_vector)
{
    for(auto value: neuer_vector)
    {
        fmt::print("Vectorvalue: {}\n",value);
    }
}