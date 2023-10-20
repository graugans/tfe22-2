#include <fmt/chrono.h>
#include <fmt/format.h>
#include <vector>
#include <random>
#include <algorithm>

#include "CLI/CLI.hpp"
#include "config.h"

// Funktion zur Ausgabe eines Vektors mit {fmt}
template <typename T>
void print_vector(const std::vector<T>& vec) {
    fmt::print("Vector Values: ");
    for (const T& value : vec) {
        fmt::print("{} ", value);
    }
    fmt::print("\n");
}

auto main(int argc, char **argv) -> int {
    CLI::App app{PROJECT_NAME};
    int count = 20;

    try {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count", count, "Anzahl festlegen")->check(CLI::Range(0, 100));
        app.parse(argc, argv);
    } catch (const CLI::ParseError &e) {
        return app.exit(e);
    }

    fmt::print("Hello, {}!\n", app.get_name());

    // Erstelle einen std::vector mit zufälligen Werten von 1-100
    std::vector<int> random_values;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 100);

    for (int i = 0; i < count; ++i) {
        random_values.push_back(dis(gen));
    }

    // Rufe die Funktion zur Ausgabe des ursprünglichen Vektors auf
    fmt::print("Ursprünglicher Vektor: ");
    print_vector(random_values);

    // Sortiere den Vektor aufsteigend
    std::sort(random_values.begin(), random_values.end());

    // Rufe die Funktion zur Ausgabe des sortierten Vektors auf
    fmt::print("Sortierter Vektor: ");
    print_vector(random_values);

    return 0;
}
