#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

#include <vector>
#include <cstdlib>

auto print_vector(const std::vector<int32_t>& vec) -> void
{
    fmt::print("{}\n", fmt::join(vec, ", "));
}

auto main(int argc, char **argv) -> int
{
    int32_t count = 20;
    std::vector<int32_t> rand_numbers;
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option<int32_t>("-c, --count", count);
        app.parse(argc, argv);

        srand((unsigned) time(NULL));

        for (int32_t i = 0; i < count; i++)
        {
            rand_numbers.push_back(1 + (rand() % 100));
        }
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
    std::cout << "raw: ";
    print_vector(rand_numbers);

    auto start = std::chrono::system_clock::now();
    std::sort(rand_numbers.begin(), rand_numbers.end());
    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "sorted in : ";
    print_vector(rand_numbers);
    fmt::print("sorted in {}\n", elapsed);



    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
}
