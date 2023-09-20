cmake_minimum_required(VERSION 3.26)
project(WordleHack)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES main.cpp)
add_executable(WordleHack main.cpp)

include_directories(utils)
add_subdirectory(utils)

target_link_libraries(WordleHack utils_lib)

add_subdirectory(google_tests)
