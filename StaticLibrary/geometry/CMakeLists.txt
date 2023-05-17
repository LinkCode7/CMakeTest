cmake_minimum_required(VERSION 3.20)
project(geometry)

file(GLOB GEO_SRC *.cpp)

# 生成静态库
add_library(${PROJECT_NAME} STATIC ${GEO_SRC})
