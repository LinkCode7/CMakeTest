# Webassembly的CMake标准项目
## 依赖
- [emsdk](https://github.com/emscripten-core/emsdk.git)
- [googletest](https://github.com/google/googletest.git)，只需将项目clone到thirdparty目录

## 构建
- cd到根目录下的build目录下，emcmake cmake .. -DCMAKE_BUILD_TYPE=Debug，emmake make -j6

## 开启服务
- 以管理员身份启动CMD，cd到根目录，http-server

