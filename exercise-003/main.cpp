#include <fmt/chrono.h>
#include <fmt/format.h>

#include "vectorint.hpp"

#define NUMBER_OF_VAlUES 2000

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

    fmt::print("initial vector: ");
    data.print_vector();
    
    fmt::print("push_back:      ");
    data.push_back(14);
    data.print_vector();

    fmt::print("Value at:       {}\n", data.at(20));

    fmt::print("Size of Vector: {}\n", data.size());
    

    fmt::print("resize:         ");
    data.resize(10);
    data.print_vector();

    data.clear();

    VectorInt data2(100);

    
    auto start = std::chrono::system_clock::now();
    for(int i = 0; i<NUMBER_OF_VAlUES; i++)
    {
        data2.push_back(10);
    }

    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    fmt::print("time needed for pushing back 100 Values (trivial): {}\n", elapsed);

    VectorInt data3(100);

    
    auto start1 = std::chrono::system_clock::now();
    for(int i = 0; i<NUMBER_OF_VAlUES; i++)
    {
        data3.push_back_better(10);
    }

    auto end1 = std::chrono::system_clock::now();
    auto elapsed1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);

    fmt::print("time needed for pushing back 100 Values (optimized): {}\n", elapsed1);

    return 0; /* exit gracefully*/

}
