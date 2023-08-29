cmake_minimum_required(VERSION 3.20)
project(ProjectName)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)

if(EMSCRIPTEN) # emscripten
else()
add_subdirectory(thirdparty/googletest)
add_subdirectory(unittest)
endif()
