cmake_minimum_required(VERSION 3.10)
project(lw3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main main.cpp point.cpp array.cpp rhomb.cpp pentagone.cpp hexagon.cpp)
add_executable(test tests.cpp point.cpp array.cpp rhomb.cpp pentagone.cpp hexagon.cpp)

target_include_directories(test PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(test PRIVATE gtest gtest_main)