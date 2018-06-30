# Minimum CMake required
cmake_minimum_required(VERSION 3.1)

# Project
project(symbol_visibility C CXX)

# Set C++11 as standard for the whole project
set(CMAKE_CXX_STANDARD 11)

# Build the libraries with -fPIC
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories("${PROJECT_SOURCE_DIR}")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS OFF)
add_library(foo_bar foo_bar.cc)
if(NOT MSVC)
  set_target_properties(foo_bar PROPERTIES COMPILE_FLAGS "-fvisibility=hidden")
endif()

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(foo SHARED foo.cc)
target_link_libraries(foo PRIVATE foo_bar)

add_library(another_bar SHARED another_bar.cc)

add_executable(main1 main.cc)
target_link_libraries(main1 PUBLIC foo another_bar)

add_executable(main2 main.cc)
target_link_libraries(main2 PUBLIC another_bar foo)
