cmake_minimum_required(VERSION 3.20)
project(geometry)

file(GLOB GEO_SRC *.cpp)
file(GLOB GEO_SRC ./entity/*.cpp)

# 生成静态库
add_library(${PROJECT_NAME} SHARED ${GEO_SRC})

# 设置输出路径
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

add_compile_definitions(GEOMETRY_MODULE)
