cmake_minimum_required(VERSION 3.20)
project(Project)

set(CMAKE_CXX_STANDARD 17)

if (CMAKE_BUILD_TYPE STREQUAL Debug)
    add_compile_definitions(_DEBUG)
endif()

# 主体项目文件
aux_source_directory(. SRCS)
aux_source_directory(geometry SRCS)



if(EMSCRIPTEN) # emscripten

# set(CMAKE_VERBOSE_MAKEFILE ON)
aux_source_directory(wasm SRCS)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --js-library ../test.js")
#set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "--strip-all  --no-entry --allow-undefined --lto-O2 --demangle --export-all")
#set_target_properties(client PROPERTIES LINK_FLAGS "-s DEMANGLE_SUPPORT=1 --preload-file ${CMAKE_SOURCE_DIR}/assets --bind")

if (CMAKE_BUILD_TYPE STREQUAL Debug) # 调试信息-sVERBOSE=1
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g --bind")
else()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")#--emit-symbol-map
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
add_executable(${PROJECT_NAME} ${SRCS})

# set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "${CMAKE_CXX_FLAGS}")

else()

add_library(${PROJECT_NAME} STATIC ${SRCS})

endif()



# 显示所有编译警告，这会显著地降低编译效率
#target_compile_options(${PROJECT_NAME} PUBLIC -Wall)

# 日志
message(">>> SRCS: " ${SRCS})
message(">>> CMAKE_CXX_FLAGS: " ${CMAKE_CXX_FLAGS})
message(">>> CMAKE_BUILD_TYPE: " ${CMAKE_BUILD_TYPE})
