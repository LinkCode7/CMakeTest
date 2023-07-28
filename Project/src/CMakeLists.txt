cmake_minimum_required(VERSION 3.20)
project(Project)

set(CMAKE_CXX_STANDARD 20)


file(GLOB SRC
       ${PROJECT_SOURCE_DIR}/*.cc
       ${PROJECT_SOURCE_DIR}/geometry/*.cc)

add_library(${PROJECT_NAME} ${SRC})

message(">>> SRC=${SRC}")
