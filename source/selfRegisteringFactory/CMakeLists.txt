add_library(converters SHARED
 "tiffFileConverter.cpp"
 "jsonFileConverter.cpp"
)

add_library(srfl SHARED
 "selfRegisteringFactory.cpp"
)


target_include_directories(converters PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_include_directories(srfl PUBLIC "${CMAKE_SOURCE_DIR}/include")