#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"
#include<cstdlib>

int count = 42;

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
        app.add_option("-c, --count", count);
        app.parse(argc, argv);

        srand((unsigned) time(NULL));

        std::vector<int> random_numbers;

        for (int i = 0; i < count; i++)
        {
            int random = 1 + (rand() % 100);
            random_numbers.push_back(random);
            std::cout << "Random Number:" << random << "\n";
        }
        fmt::print("Vektor: {}\n", fmt::join(random_numbers, " und "));

        
        
        
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
    std::cout << "Count: " << count << "\n";
    

    return 0; /* exit gracefully*/
}
