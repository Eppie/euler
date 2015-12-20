cmake_minimum_required(VERSION 2.6)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
file(GLOB source *.cpp)
add_executable(runTests ${source})
target_compile_features(runTests PUBLIC cxx_auto_type)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

