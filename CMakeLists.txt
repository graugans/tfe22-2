cmake_minimum_required (VERSION 3.10.2)

# Set the project name to your project name, template isn't very descriptive
project (TFE22-2)

# Conditionally turn on/off parts of the build (global-level)
option(BUILD_TESTS "Build unit tests" ON)


# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include dependencies
find_package(fmt REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(CLI11 CONFIG REQUIRED)
find_package(Catch2 3 REQUIRED)

# Set the OUTPUT dirs
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(TEST_REPORT_DIRECTORY ${CMAKE_BINARY_DIR}/reports)
file(MAKE_DIRECTORY ${TEST_REPORT_DIRECTORY})


# test helpers
# Catch2 should output in JUnit format, and output successful tests, too
set (CATCH2_DEFAULT_PARAMETERS -r junit)
macro (add_catch2_test)
    set(prefix ADD_CATCH2_TEST)
    set(oneValueArgs TARGET WORKING_DIR)
    cmake_parse_arguments(${prefix} "" "${oneValueArgs}" "" ${ARGN} )
    if(NOT DEFINED ${prefix}_WORKING_DIR)
        set(${prefix}_WORKING_DIR ${CMAKE_BINARY_DIR})
    endif()
    add_test(
        NAME ${${prefix}_TARGET}
        COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${${prefix}_TARGET} -o ${TEST_REPORT_DIRECTORY}/${${prefix}_TARGET}.xml ${CATCH2_DEFAULT_PARAMETERS}
        WORKING_DIRECTORY ${${prefix}_WORKING_DIR}
    )
endmacro(add_catch2_test)

# Introduce the Build test parameter as a define in the compiler flags
if(BUILD_TESTS)
    enable_testing()
endif()


# Some useful default settings
include(cmake/StandardProjectSettings.cmake)
# Prevent people from messing with stuff
include(cmake/PreventInSourceBuilds.cmake)

# allow for static analysis options
include(cmake/StaticAnalyzers.cmake)

# enable doxygen
include(cmake/Doxygen.cmake)

# Exercises & solutions
add_subdirectory(exercise-001)
add_subdirectory(exercise-002)
add_subdirectory(exercise-003)

# templates
add_subdirectory(templates)


