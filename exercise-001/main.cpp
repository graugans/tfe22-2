#include <fmt/chrono.h>
#include <fmt/format.h>

#include <random>
#include "CLI/CLI.hpp"
#include "config.h"

auto main(int argc, char **argv) -> int
{
    auto count = 20;
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c, --count", count, fmt::format("The default is:{}",count));
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
    


    // Initialize random time seed 
    srand ( time(NULL) );   

    std::vector<uint32_t> vec_random;
    for (int i = 0; i <= 20; i++)
        vec_random.push_back(rand() % 100 + 1); // Add a random number between 1 and 100
    
    auto start = std::chrono::system_clock::now();
    std::sort(vec_random.begin(), vec_random.end());
    auto end = std::chrono::system_clock::now();
    auto elapsed =
    std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);


    fmt::print("The values of the vector: {} \n", fmt::join(vec_random, ", "));
    fmt::print("Time it took to sort the vector (in ms): {}", elapsed);

    return 0; /* exit gracefully*/
}
