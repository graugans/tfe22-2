#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"
#include <random>

auto printVector(const std::vector<int>& Zufall) {
    fmt::print("Vektorinhalt: ");
    for(const auto &value : Zufall)
     {
        fmt::print("{}\n", value);
    }
    
}

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    
    CLI::App app{PROJECT_NAME};
    int  count = 20;
    std::random_device rd;
    std::vector<int> Zufall(count);

    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> Zufallszahl(1,100);

    for (std::vector<int>::size_type i = 0; i != Zufall.size(); ++i)
    {
        std::uniform_int_distribution<int> Zufallszahl(1,100);
        Zufall[i] = Zufallszahl(generator);
       
    }

    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count", count, "Zähler zum ändern");
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
   

    CLI11_PARSE(app, argc, argv);
    fmt::print("Parameter, {}\n", count);
    //for(auto value: Zufall){}
    printVector(Zufall);

    
    fmt::print("Sortierter Inhalt: ");
    
    auto start = std::chrono::system_clock::now();
    std::sort(Zufall.begin(), Zufall.end());
    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    
    for(const auto &value : Zufall)
     {
        fmt::print("{}\n", value);
    }
    fmt::print("Zeit benötigt:{}\n", elapsed);
    return 0; /* exit gracefully*/
}
