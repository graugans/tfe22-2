#include <fmt/chrono.h>
#include <fmt/format.h>
#include <vector>
#include <random>

#include "CLI/CLI.hpp"
#include "config.h"

auto main(int argc, char **argv) -> int
{
    CLI::App app{PROJECT_NAME};
    int count = 20;

    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count", count, "Anzahl festlegen")->check(CLI::Range(0, 100));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
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

    fmt::print("Random Values: ");
    for (int value : random_values) {
        fmt::print("{} ", value);
    }
    fmt::print("\n");

    return 0;
}
