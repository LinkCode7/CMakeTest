# 设置项目所需的最低的 cmake 版本
cmake_minimum_required(VERSION 3.20)

# 设置项目名称
project(HelloWorld)

# 把要编译的源文件（不需要指定头文件）放到自定义变量SRC中
file(GLOB SRC main.cpp)

# 根据SRC中的源文件，生成可执行目标
add_executable(HelloWorld ${SRC})



# 扩展
# ${SRC}的意思是引用变量SRC所指的东西

# 以下语句会将常用的内置变量打印到IDE控制台
message(">>> SRC =" ${SRC})
message(">>> CMAKE_SOURCE_DIR = " ${CMAKE_SOURCE_DIR})
message(">>> CMAKE_BINARY_DIR = " ${CMAKE_BINARY_DIR})
message(">>> PROJECT_SOURCE_DIR = " ${PROJECT_SOURCE_DIR}) # 项目中含有子项目时...
message(">>> PROJECT_BINARY_DIR = " ${PROJECT_BINARY_DIR})

message(">>> LIBRARY_OUTPUT_NAME = " ${LIBRARY_OUTPUT_NAME})
message(">>> LIBRARY_OUTPUT_PATH = " ${LIBRARY_OUTPUT_NAME})

message(">>> CMAKE_RUNTIME_OUTPUT_DIRECTORY = " ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
message(">>> CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG = " ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG})