cmake_minimum_required(VERSION 3.20)

project(MultiExe)

file(GLOB SRC ${PROJECT_SOURCE_DIR}/*.cc)

#include_directories("${PROJECT_BINARY_DIR}")

# Find all main*.cc files and store in list SRC
#file(GLOB_RECURSE SRC RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/main*.cc")

set(yLT_ALL_PROJECTS "main1;main2")
list(APPEND yLT_ENABLE_PROJECTS main1)
list(APPEND yLT_ENABLE_PROJECTS main2)


message(">>> SRC"=${SRC})
message(">>> yLT_ENABLE_PROJECTS"=${yLT_ENABLE_PROJECTS})

foreach(mainfile IN LISTS yLT_ALL_PROJECTS)
    # Get file name without directory
    #get_filename_component(mainname ${mainfile} NAME_WE)
    add_executable(${mainfile} ${SRC})
endforeach()


#add_executable(main1 ${SRC})
#add_executable(main2 ${SRC})
