cmake_minimum_required(VERSION 2.8)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

project(Sieve_of_Eratosthenes)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-Wall -g -std=c++11")
message("Making with CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS}")

enable_testing(true)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Tests/)
