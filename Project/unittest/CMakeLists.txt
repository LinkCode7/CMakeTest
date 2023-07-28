cmake_minimum_required(VERSION 3.20)
project(unittest)
set(CMAKE_CXX_STANDARD 20)

#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
file(GLOB SRC_TEST ${PROJECT_SOURCE_DIR}/*.cc)

add_executable(${PROJECT_NAME} ${SRC_TEST})

target_link_libraries(${PROJECT_NAME} Project)
target_link_libraries(${PROJECT_NAME} gtest gtest_main)

target_include_directories(${PROJECT_NAME} PRIVATE ../thirdparty/googletest/googletest/include)
