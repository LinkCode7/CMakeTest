cmake_minimum_required(VERSION 3.20)
project(LinkStaticLibrary)

file(GLOB SRC *.cpp)

add_subdirectory(geometry)

add_executable(${PROJECT_NAME} ${SRC})

# 链接库文件
target_link_libraries(${PROJECT_NAME} geometry)