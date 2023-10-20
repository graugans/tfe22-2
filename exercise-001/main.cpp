#include <fmt/chrono.h>
#include <fmt/format.h>
#include <vector>
#include <random>
#include "CLI/CLI.hpp"
#include "config.h"

auto main(int argc, char **argv) -> int
{
    int count = 20;
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count", count, "Set the count value");
        app.parse(argc, argv);
        fmt::print("count: {}\n", count);
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
    std::vector<int> vec(count);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    std::generate_n(vec.begin(), count, [&dis, &gen]() { return dis(gen); });
    return 0; /* exit gracefully*/
}


