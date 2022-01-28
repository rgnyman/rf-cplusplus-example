cmake_minimum_required(VERSION 3.20)
project(Refactoring)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

add_executable(Refactoring_run main.cpp)

include_directories(movie)
add_subdirectory(movie)
add_subdirectory(rf-tests)

target_link_libraries(Refactoring_run movie_lib)

add_subdirectory(Google_tests)
