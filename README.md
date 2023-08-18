# CMakeTest

## 目录介绍

|      项目      |                                   说明                                   |                                     命令                                      |
| :------------: | :----------------------------------------------------------------------: | :---------------------------------------------------------------------------: |
|      File      |                       一个最简单的 HelloWorld 项目                       |                                add_executable                                 |
|     File2      |                             多个源文件的项目                             |                                     file                                      |
|     File3      |                        多个目录、多个源文件的项目                        |                          file、aux_source_directory                           |
| StaticLibrary  |           将工程内的子目录编译为静态库，供工程内的其它文件使用           |             add_subdirectory、add_library、target_link_libraries              |
| StaticLibrary2 | 将工程内的子目录编译为静态库，并指定库的输出路径，供工程内的其它文件使用 |                                       -                                       |
| DynamicLibrary |                       将工程内的子目录编译为动态库                       | add_subdirectory、add_library、target_link_libraries、\_\_declspec(dllexport) |
|   GoogleTest   |                       动态链接 googletest 到工程内                       |            find_library、target_link_libraries、add_custom_command            |
|    Project     |            标准工程，包含主项目，第三方依赖（静态），单元测试，文档等            |                                                                               |

## 实用的命令

- 添加宏定义：target_compile_definitions

```cpp
# cmake version >= 2.8.11
string(TIMESTAMP MyDateVersion "%Y%m%d")
string(TIMESTAMP MyDateTime "%Y-%m-%d %H:%M:%S")
add_compile_definitions(MY_DATE_VERSION="${MyDateVersion}") # "20230504"
```

## 其它

- 编译 googletest
  > 1.  [下载 googletest 源码](https://github.com/google/googletest)
  > 2.  cmake .. -DCMAKE_BUILD_TYPE=Debug // 编译配置（debug 版本）
  > 3.  cmake --build . // 编译
