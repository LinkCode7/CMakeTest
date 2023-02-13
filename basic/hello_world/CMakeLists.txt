cmake_minimum_required(VERSION 3.20)
project(HelloWorld)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SRC
       ${PROJECT_SOURCE_DIR}/*.cpp
       ${PROJECT_SOURCE_DIR}/*.h)

# 打印SRC中列表信息
message(STATUS ">>> SRC = ${SRC}")

add_executable(${PROJECT_NAME} ${SRC})
