#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

// .bss segment only in SRAM/RAM
static int foo;
static int foo2;

// .data segment in Flash and SRAM
int data = 100;
int data2 = 101;

// .rodata segment in Flash only
const int rodata = 100;
const int rodata2 = 101;


void myfunction(int* param ) {
    /*static*/ int var = 0;
    fmt::print("value of var {} address of var {}\n",var,fmt::ptr(&var));
    fmt::print("value of param {} address of param {}\n",*param,fmt::ptr(param));
    var = var + 1;
    *param = *param + var;
    /*delete param;*/
}


auto main(int argc, char **argv) -> int
{
    int hugo;
    int *pData = new int;
    *pData = 4711;
    fmt::print("The value of foo {} the address of foo: {}\n", foo, fmt::ptr(&foo));
    fmt::print("The value of foo2 {} the address of foo2: {}\n", foo2, fmt::ptr(&foo2));
    fmt::print("The value of data {} the address of data: {}\n", data, fmt::ptr(&data));
    fmt::print("The value of data2 {} the address of data2: {}\n", data2, fmt::ptr(&data2));
    fmt::print("The value of rodata {} the address of rodata: {}\n", rodata, fmt::ptr(&rodata));
    fmt::print("The value of rodata2 {} the address of rodata2: {}\n", rodata2, fmt::ptr(&rodata2));
    
    fmt::print("The value of hugo {} the address of hugo: {}\n", hugo, fmt::ptr(&hugo));
    fmt::print("The value of pData {} the address of pData: {}\n", *pData, fmt::ptr(pData));
    int bar = 42;
    myfunction(pData);
    fmt::print("The value of bar {} the address of bar: {}\n", bar, fmt::ptr(&bar));
    bar = 47;
    *pData = 23;
    myfunction(pData);
    fmt::print("The value of pData {} the address of pData: {}\n", *pData, fmt::ptr(pData));
    fmt::print("The value of bar {} the address of bar: {}\n", bar, fmt::ptr(&bar));

    return 0; /* exit gracefully*/
}
