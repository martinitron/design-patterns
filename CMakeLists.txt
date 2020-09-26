cmake_minimum_required(VERSION 3.10)
project(design-patterns)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(source)

add_executable(DesignPatterns
main.cpp
)

target_include_directories(DesignPatterns PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(DesignPatterns patterns)
