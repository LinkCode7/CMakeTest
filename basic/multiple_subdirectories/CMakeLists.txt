cmake_minimum_required(VERSION 3.20)
project(MultipleSubdirectories)

set(CMAKE_CXX_STANDARD 11)

# 查找当前目录下的所有源文件，并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 添加 math 子目录，这样 math 目录下的 CMakeLists.txt 文件和源代码也会被处理
add_subdirectory(math)

# 生成指定目标
add_executable(${PROJECT_NAME} main.cpp)

# 链接库
target_link_libraries(${PROJECT_NAME} MathFunctions)
