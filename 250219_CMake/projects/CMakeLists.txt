cmake_minimum_required(VERSION 3.2...3.27.5)

project(Well-_-)

enable_testing()
add_subdirectory(lib/googletest)

add_subdirectory(multilevel_menu)
add_subdirectory(sort)

set(CMAKE_SUPPRESS_REGENERATION true)