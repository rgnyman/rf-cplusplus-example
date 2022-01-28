cmake_minimum_required(VERSION 3.20)
project(movie_tests)

set(CMAKE_CXX_STANDARD 17)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR}})

add_executable(movie_tests_run CustomerTest.cpp)

target_link_libraries(movie_tests_run movie_lib)

target_link_libraries(movie_tests_run gtest gmock gtest_main)
