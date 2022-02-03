# rf-cplusplus-example
Example how to connect [Robot Framework](https:://robotframework.org) to c++ application using [Pybind11](https://pybind11.readthedocs.io/en/stable/)

Application that is tested is simple Movie library modified from Martin Fowlers movie library refactoring example. There is plenty of functionality missing from Movie library that can be added using TDD and ATDD.

# Prerequisite
Working C++ compilation environment with CMake
Working Python 3=> environment

# Installation
Clone the repository. 
Install [Pydind11](https://pybind11.readthedocs.io/en/stable/installing.html)
Install [Robot Framework](https://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html#installation-instructions)

# Building
After cloning repostiry run CMake
    cmake -S ./ -B build

# Running tests
Robot Framework
    robot rf-tests/movie-rental-tests.txt
