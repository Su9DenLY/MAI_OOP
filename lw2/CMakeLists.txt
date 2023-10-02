cmake_minimum_required(VERSION 3.10)
project(lw2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main main.cpp seven.cpp)
add_executable(test tests.cpp seven.cpp)

target_include_directories(test PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(test PRIVATE gtest gtest_main)