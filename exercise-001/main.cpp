#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

auto main(int argc, char **argv) -> int
{
    CLI::App app{PROJECT_NAME};
    int count = 20; // Standardwert

    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        
        // Füge eine Option für "count" hinzu
        app.add_option("-c,--count", count, "Anzahl festlegen")->check(CLI::Range(0, 100));

        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    fmt::print("Hello, {}!\n", app.get_name());
    fmt::print("Count: {}\n", count); // Gib den Wert von "count" aus

    return 0;
}