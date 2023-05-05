# CMakeTest

## 目录介绍
| 项目 | 说明 | 命令 |
| :---:| :---: | :---: |
File1 | 一个最简单的HelloWorld项目 | add_executable
File2 | 多个源文件的项目 | file
File3 | 多个目录、多个源文件的项目 | file、aux_source_directory
StaticLibrary1 | 将工程内的子目录编译为静态库，供工程内的其它文件使用 | add_subdirectory、add_library、target_link_libraries
StaticLibrary2 | 将工程内的子目录编译为静态库，并指定库的输出路径，供工程内的其它文件使用 | 




## 实用的命令
- 添加宏定义：target_compile_definition
```cpp
# cmake version >= 2.8.11
string(TIMESTAMP MyDateVersion "%Y%m%d")
string(TIMESTAMP MyDateTime "%Y-%m-%d %H:%M:%S")
add_compile_definitions(MY_DATE_VERSION="${MyDateVersion}") # "20230504"
```
