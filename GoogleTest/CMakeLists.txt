cmake_minimum_required(VERSION 3.12)
project(GoogleTest)

set(CMAKE_CXX_STANDARD 11)

# 设置输出路径，dll和exe必须在同一目录，否则运行时无法继续执行
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

include_directories("third_party/googletest/include")
set(GOOGLE_TEST_LIB_DIR "third_party/googletest/lib")
set(GOOGLE_TEST_DLLS "${CMAKE_SOURCE_DIR}/${GOOGLE_TEST_LIB_DIR}/gtest.dll")

# 工程文件
file(GLOB SRCS ${PROJECT_SOURCE_DIR}/*.cc)


add_executable(${PROJECT_NAME} ${SRCS})


# 动态链接googletest
find_library(GTEST gtest ${GOOGLE_TEST_LIB_DIR})
find_library(GTEST_MAIN gtest_main ${GOOGLE_TEST_LIB_DIR})
target_link_libraries(${PROJECT_NAME} ${GTEST} ${GTEST_MAIN})

if(NOT GTEST)
    message(FATAL_ERROR "GTEST not found")
endif()
if(NOT GTEST_MAIN)
    message(FATAL_ERROR "GTEST_MAIN not found")
endif()

# 拷贝dll
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${GOOGLE_TEST_DLLS} $<TARGET_FILE_DIR:${PROJECT_NAME}>)
