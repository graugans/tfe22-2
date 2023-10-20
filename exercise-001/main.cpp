#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

#include <vector>   // Header-Datei für std::vector
#include <random>   // Header-Datei für die Zufallsgenerierung
#include <algorithm> // Header-Datei für std::sort

// Funktion zur Ausgabe des Vektors mit zufälligen Zahlen
void printRandomNumbers(const std::vector<int>& numbers) {
    fmt::print("Zufällige Zahlen: ");
    for (int num : numbers) {
        fmt::print("{} ", num);
    }
    fmt::print("\n");
}


auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};

    int count = 20;

    app.add_option("-c,--count", count, "Anzahl der Elemente");

    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
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
    //fmt::print("Count", app.add_flag());  //hinzugefügt

    fmt::print("Count: {}\n", count);

    // Erstellen eines std::vector mit der Größe von "count" und gefüllt mit zufälligen Werten von 1 bis 100
    std::vector<int> randomNumbers;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 100);

    for (int i = 0; i < count; ++i) {
        randomNumbers.push_back(dis(gen));
    }

    // Anzeigen der zufälligen Zahlen
    printRandomNumbers(randomNumbers);

     // Sortieren Sie den Vektor in aufsteigender Reihenfolge
    std::sort(randomNumbers.begin(), randomNumbers.end());

    // Geben Sie den sortierten Vektor aus
    fmt::print("Sortierte Zufallszahlen: ");
    for (int num : randomNumbers) {
        fmt::print("{} ", num);
    }
    fmt::print("\n");

    return 0; 
}
