cmake_minimum_required(VERSION 3.20)
project(MultipleFile)

# 把要编译的源文件放到自定义变量SRC中
file(GLOB SRC *.cpp) # 这里等同于：file(GLOB SRC main.cpp a.cpp b.cpp)

add_executable(${PROJECT_NAME} ${SRC})

# file命令还有很多用法，请参考：https://cmake.org/cmake/help/v3.14/command/file.html