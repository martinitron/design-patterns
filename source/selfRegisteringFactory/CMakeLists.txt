add_library(srfl OBJECT
selfRegisteringFactory.cpp
)

target_include_directories(srfl PUBLIC "${CMAKE_SOURCE_DIR}/include")