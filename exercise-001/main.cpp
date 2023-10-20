#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */

    CLI::App app{PROJECT_NAME};
    int count = 20;
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count",count,fmt::format("Count: {}\n", count));
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
    fmt::print("Count: {}!\n", count);

    std::vector

    
   /*
    app.add_option("-c,--count",count,fmt::format("Count: {}\n", count));
    app.parse(argc, argv);

    using vtype=std::variant<int, double, std::string>;
    vtype v1;
    //app.add_option<vtype,std:string>("--vs",v1);
    app.add_option<vtype,int>("--count",count);
    //app.add_option<vtype,double>("--vf",v1);
    fmt::print("Count: %d\n", count);
*/

    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
}
