cmake_minimum_required(VERSION 3.21.2)
project(cmake)
add_executable(hello_yaka src/main.cc)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(libyaka)

add_compile_options(-Wall -Wextra -Werror -pedantic -std=c++20 -Wold-style-cast)
