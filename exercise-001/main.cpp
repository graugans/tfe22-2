#include <fmt/chrono.h>
#include <fmt/format.h>
#include <random>  // Für Zufallszahlen
#include <vector>
#include <algorithm>  // Für std::sort
#include <chrono>  // Für Zeitmessung

#include "CLI/CLI.hpp"
#include "config.h.in"

// Funktion zur Ausgabe eines Vektors mit der {fmt} Bibliothek
template <typename T>
void printVector(const std::vector<T>& vec) {
    fmt::print("Vektor:");
    for (const T& value : vec) {
        fmt::print(" {}", value);
    }
    fmt::print("\n");
}

auto main(int argc, char **argv) -> int
{
    CLI::App app{PROJECT_NAME};

    int count = 20; // Standardwert

    try
    {
        app.add_option("-c,--count", count, "set count;")->check(CLI::Range(0, 100));
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    // Erzeugen Sie einen Zufallszahlengenerator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);

    // Erstellen Sie einen std::vector mit zufälligen Werten
    std::vector<int> random_values(count);
    for (int &value : random_values) {
        value = dist(gen);
    }

    fmt::print("Hello, {}!\n", app.get_name());
    fmt::print("count: {}\n", count);

    // Zeitmessung vor dem Sortieren
    auto start_time = std::chrono::high_resolution_clock::now();

    // Sortieren Sie den Vektor in aufsteigender Reihenfolge
    std::sort(random_values.begin(), random_values.end());

    // Zeitmessung nach dem Sortieren
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    // Ausgabe der Sortierzeit
    fmt::print("Sortierzeit: {} Mikrosekunden\n", duration.count());

    // Rufen Sie die Funktion zur Ausgabe des sortierten Vektors auf
    printVector(random_values);

    return 0; /* graceful exit */
}