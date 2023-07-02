cmake_minimum_required(VERSION 3.0.0)
project(modern_cpp_learn VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(modern_cpp_learn src/main.cpp)

add_executable(basic_nullptr src/basic/nullptr.cpp)
add_executable(basic_constexpr src/basic/constexpr.cpp)
add_executable(basic_tuple src/basic/tuple.cpp)

add_executable(template_demo1 src/template/demo1.cpp)
add_executable(template_demo2 src/template/demo2.cpp)



