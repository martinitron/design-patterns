add_subdirectory(selfRegisteringFactory)

add_library(patterns STATIC
$<TARGET_OBJECTS:srfl>)

target_include_directories(patterns PUBLIC "${CMAKE_SOURCE_DIR}/include")
