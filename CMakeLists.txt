cmake_minimum_required(VERSION 3.28)
project(DesignPatterns)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add_subdirectory(source)

set(CONVERTERS_LIB_NAME "converters")

add_library(${CONVERTERS_LIB_NAME} SHARED
 "source/selfRegisteringFactory/tiffFileConverter.cpp"
 "source/selfRegisteringFactory/jsonFileConverter.cpp"
 "source/selfRegisteringFactory/converterVersions.cpp"
)

target_include_directories(${CONVERTERS_LIB_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/include")

add_executable(${PROJECT_NAME}
"main.cpp"
"source/selfRegisteringFactory/selfRegisteringFactory.cpp"
"source/selfRegisteringFactory/fileConverterProxyBase.cpp"
)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_link_directories(${PROJECT_NAME} PUBLIC "${CMAKE_BIN_DIR}" "${CMAKE_BIN_DIR}/source" "${CMAKE_BIN_DIR}/source/selfRegisteringFactory")
# target_link_libraries(DesignPatterns "${CMAKE_SOURCE_DIR}/source/selfRegisteringFactory/libconverters.so") #converters
target_link_libraries(${PROJECT_NAME} "${CONVERTERS_LIB_NAME}")
# target_link_libraries(${PROJECT_NAME} "-L/${CMAKE_BIN_DIR}/source/selfRegisteringFactory/" -lconverters)
