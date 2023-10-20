#include <fmt/chrono.h>
#include <fmt/format.h>
#include <random>  // Für Zufallszahlen
#include <vector>

#include "CLI/CLI.hpp"
#include "config.h.in"

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

    // Ausgabe der zufälligen Werte
    fmt::print("Zufällige Werte:");
    for (int value : random_values) {
        fmt::print(" {}", value);
    }
    fmt::print("\n");

    return 0; /* graceful exit */
}