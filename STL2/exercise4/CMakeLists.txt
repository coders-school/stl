cmake_minimum_required(VERSION 2.6)
project(basic_test)

set(CMAKE_CXX_STANDARD 17)

################################
# GTest
################################
#### PLEASE CHANGE PATH TOU YOUR GTEST DIRECTORY ####
ADD_SUBDIRECTORY (C:/Users/Iorwet/Documents/repoGit/C++/SHM/googletest gtest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

################################
# Unit Tests
################################
# Add test cpp file
add_executable( test_exercise test_exercise4.cpp )
# Link test executable against gtest & gtest_main
target_link_libraries(test_exercise gtest gtest_main)
add_test( test_exercise test_exercise )
