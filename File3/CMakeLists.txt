cmake_minimum_required(VERSION 3.20)
project(MultipleDirectories)

# 查找目录中所有源文件，并存储到SRC中
#aux_source_directory(. SRC)
#aux_source_directory(database SRC)
#aux_source_directory(database/sql SRC)
#aux_source_directory(entity SRC)

# 以下方法同样可行
file(GLOB SRC
       ${PROJECT_SOURCE_DIR}/*.cpp
       ${PROJECT_SOURCE_DIR}/database/*.cpp
       ${PROJECT_SOURCE_DIR}/database/sql/*.cpp
       ${PROJECT_SOURCE_DIR}/entity/*.cpp)

#file(GLOB_RECURSE SRC ${PROJECT_SOURCE_DIR}/*.cpp) # 会遍历子目录，包括out、build目录中不需要的源文件

add_executable(${PROJECT_NAME} ${SRC})

message(">>> SRC = " ${SRC})
