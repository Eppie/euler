cmake_minimum_required(VERSION 2.8)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_EXE_LINKER_FLAGS  ${CMAKE_EXE_LINKER_FLAGS} "-lgmpxx -lgmp")

add_definitions(-std=c++14 -g -Ofast -Weverything -Wno-c++14-binary-literal -Wno-c++98-compat -Wno-header-hygiene -Wno-missing-prototypes -Wno-global-constructors -Wno-sign-compare -Wno-sign-conversion -Wno-shorten-64-to-32 -Wno-c++98-compat-pedantic -Wno-return-type -Wno-float-conversion -Wno-missing-variable-declarations -Wno-shadow -Wno-unused-exception-parameter)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB_RECURSE euler_source [0-9]/*.cpp main.cpp helper.cpp)
file(GLOB test_source test/*.cpp helper.cpp)

add_executable(euler ${euler_source})
add_executable(runTests ${test_source})

# Link runTests with what we want to test and the GTest and pthread library
target_compile_features(runTests PUBLIC cxx_auto_type)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

