#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"
#include <vector>
#include <random>

auto main(int argc, char **argv) -> int
{
    int count = 20;

    CLI::App app{PROJECT_NAME};
    try
    {
        app.add_option("-c,--count", count, "set count:") -> check(CLI::Range(0,100));
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    fmt::print("Hello, {}!\n", app.get_name());
    fmt::print("count: {}\n", count);

    // Erstellen Sie einen std::vector und füllen ihn mit zufälligen Werten
    std::vector<int> randomValues;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 100);

    for (int i = 0; i < count; ++i) {
        randomValues.push_back(dis(gen));
    }

    fmt::print("Zufällige Werte: ");
    for (int value : randomValues) {
        fmt::print("{} ", value);
    }
    fmt::print("\n");

    return 0;
}
