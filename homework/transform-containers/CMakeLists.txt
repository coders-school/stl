cmake_minimum_required(VERSION 3.11.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        main # release-1.10.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg

project(transformContainers)
enable_testing()

add_executable(${PROJECT_NAME}-ut test.cpp mergeConteiners.cpp) # add your cpp file here after test.cpp
# if this is problematic take a look into CMakeLists.txt files in other exercises

add_compile_options(${PROJECT_NAME}-ut -Wall -Wextra -Wconversion -pedantic -Werror)

target_link_libraries(${PROJECT_NAME}-ut gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-ut)
