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

set(HEADER_FILES
lib/utils/quartile_calculator.h
lib/algorithms/iqr.h
lib/algorithm.h
lib/utils/distances/euclidean.h
lib/utils/distances/minkowski.h
lib/utils/distances/chebyshev.h
lib/utils/distance.h
)

set(SOURCE_FILES
src/utils/quartile_calculator.cpp
src/algorithms/iqr.cpp
src/utils/distances/euclidean.cpp
src/utils/distances/minkowski.cpp
src/utils/distances/chebyshev.cpp
)

add_executable(main src/main.cpp  ${SOURCE_FILES} ${HEADER_FILES})

# BUILD_TESTING variable is created by include(CTest)
# It is set to ON by default
if(BUILD_TESTING)
  add_executable(tests tests/tests_main.cpp)
  target_link_libraries(tests PRIVATE GTest::gtest_main)

  include(GoogleTest)

  # Finds all the Google tests associated with the executable
  gtest_discover_tests(tests)
endif()