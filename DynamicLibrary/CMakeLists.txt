cmake_minimum_required(VERSION 3.20)
project(LinkDynamicLibrary)

# 设置输出路径，dll和exe必须在同一目录，否则运行时无法继续执行
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

file(GLOB SRC *.cpp)

add_subdirectory(geometry)
add_executable(${PROJECT_NAME} ${SRC})

# 链接路径
link_directories(${PROJECT_SOURCE_DIR}/bin)

# 链接库文件
target_link_libraries(${PROJECT_NAME} geometry)