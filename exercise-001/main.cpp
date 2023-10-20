#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

auto start = std::chrono::system_clock::now();

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
        app.add_option("-c,--count",count,fmt::format("The amount of elements in our vector default: {}", count));
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

    std::vector<int> marius;

    for(int i=0;i<count; i++){

        marius.push_back(rand()%100+1);
    }

    for(int x=0;x<marius.size(); x++){

        std::cout << marius[x] << std::endl;
    }

    //auto start = std::chrono::system_clock::now();

    std::sort(marius.begin(), marius.end());
    std::cout << "Vektor sortiert:"<< std::endl;

    for(int x=0;x<marius.size(); x++){

        fmt::print("{}\n",marius[x]);
    }

    auto end = std::chrono::system_clock::now();
    auto Dauer =
            std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    fmt::print("Zeit der Berechnung: {}\n", Dauer);

    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
}
