#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"


#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using std::cout;
using std::endl;


void printVector(const std::vector<int>& data) {
    fmt::print("vector: [{}]\n", fmt::join(data, ", "));
}

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */

    CLI::App app{PROJECT_NAME};
    int count = 20;
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count",count,fmt::format("Count: {}\n", count));
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
    fmt::print("Count: {}!\n", count);


    std::random_device rd;
    std::mt19937 gen(rd());
    
    


    //std::for_each(data.begin(), data.end(), [&distrib, &gen](auto))
    //fmd::print("vector: \n[{}]\n", fmt::join(data,", "));

    // Create a distribution for random numbers, for example, from 1 to 100
    std::uniform_int_distribution<int> distrib(1, 100);

    // Create a vector to store random numbers
    std::vector<int> data;

    // Specify the number of random numbers you want in the vector
    const int numRandomNumbers = count;

    for (int i = 0; i < numRandomNumbers; ++i) {
        // Generate a random number and add it to the vector
        int randomNumber = distrib(gen);
        data.push_back(randomNumber);
    }

    printVector(data);
    
    std::sort(data.begin(), data.end());

    // Den sortierten Vektor ausgeben
    fmt::print("Sortierter Vektor: [{}]\n", fmt::join(data, ", "));




    return 0; /* exit gracefully*/
}
