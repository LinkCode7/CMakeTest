cmake_minimum_required(VERSION 3.20)
project(MakeDateTime)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SRC
       ${PROJECT_SOURCE_DIR}/*.cpp
       ${PROJECT_SOURCE_DIR}/*.h)

# 打印SRC中列表信息
message(STATUS ">>> SRC = ${SRC}")


# version >= 2.8.11
string(TIMESTAMP MyDateVersion "%Y%m%d")
add_compile_definitions(MY_DATE_VERSION="${MyDateVersion}")

string(TIMESTAMP MyDateTime "%Y-%m-%d %H:%M:%S")

# 输出示例：20230210
message(STATUS ">>> MyDateVersion = ${MyDateVersion}")
message(STATUS ">>> MyDateTime = ${MyDateTime}")


add_executable(${PROJECT_NAME} ${SRC})
