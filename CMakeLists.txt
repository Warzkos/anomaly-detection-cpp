cmake_minimum_required(VERSION 3.5)
project(ProjectTemplate VERSION 0.0.1
  DESCRIPTION "GoogleTest Project Template"
  LANGUAGES CXX)


# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Update submodules automatically
include(cmake/UpdateSubmodules.cmake)

# Enable testing for this project
include(CTest)

# Add subdirectories with code
add_subdirectory(external/googletest)

add_executable(main src/main.cpp lib/algorithms/iqr.hpp lib/algorithm.h)

# BUILD_TESTING variable is created by include(CTest)
# It is set to ON by default
if(BUILD_TESTING)
  add_executable(tests tests/tests_main.cpp)
  target_link_libraries(tests PRIVATE GTest::gtest_main)

  include(GoogleTest)

  # Finds all the Google tests associated with the executable
  gtest_discover_tests(tests)
endif()