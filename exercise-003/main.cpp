#include <fmt/chrono.h>
#include <fmt/format.h>

#include "vectorint.hpp"

auto main(int argc, char **argv) -> int
{
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    //fmt::print("Hello, World!\n");

    /* INSERT YOUR CODE HERE */
    VectorInt data(20);
    fmt::print("Values of the Vector:\n");
    int i = 0;
    for (int i = 0; i < data.size(); i++)
     {
        fmt::print("{},", data.at(i));
     }

    data.push_back(23);

    fmt::print("\nValues of the new Vector:\n");

     for (int i = 0; i < data.size(); i++)
     {
        fmt::print("{},", data.at(i));
     }

    return 0; /* exit gracefully*/
}
