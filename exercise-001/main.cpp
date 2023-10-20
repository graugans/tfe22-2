#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"
#include <random>
#include <algorithm> // Für std::sort
#include <chrono> // Für Zeitmessung

auto main(int argc, char **argv) -> int
{
    CLI::App app{PROJECT_NAME};
    
     /* CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    

    auto count = 20; // Standardwert
   

    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count", count, "Anzahl festlegen");
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
    fmt::print("Count: {}\n", count);

    /* INSERT YOUR CODE HERE */
    std::vector<int> randomVector;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    
    for (int i = 0; i < count; ++i) {
        randomVector.push_back(dis(gen));
    }

    auto start = std::chrono::system_clock::now();

    std::sort(randomVector.begin(), randomVector.end());

    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    
    // Ausgabe der Werte im Vektor
    fmt::print("Random Vector: ");
    for (const auto &element : randomVector) {
        fmt::print("{} ", element);
    }
    fmt::print("\n");

    fmt::print("Sortierzeit: {}\n", elapsed);

    

    return 0; /* exit gracefully*/
}
