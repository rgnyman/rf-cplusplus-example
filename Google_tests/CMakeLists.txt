cmake_minimum_required(VERSION 3.20)
project(Google_tests)

#add_subdirectory(lib)
add_subdirectory(movie_tests)

include(FetchContent)
FetchContent_Declare(
        lib
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/master.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(lib)

set(CMAKE_CXX_STANDARD 17)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR}})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
#add_executable(Google_Tests_run StringCalculatorTests_lib)

#target_link_libraries(Google_Tests_run StringCalculatorTests_lib)

#target_link_libraries(Google_Tests_run gtest gtest_main)
