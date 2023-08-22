#include "EmscriptenBinding.h"

#include <emscripten/bind.h>
#include <emscripten/val.h>

#include <iostream>
#include <sstream>

namespace sindy
{
MyPoint::MyPoint(int x, const std::string& y) : x(x), y(y)
{ // JsObject.delete()会执行构造
    std::cout << ">>> MyPoint::MyPoint(int x, const std::string& y)" << std::endl;
}
MyPoint::~MyPoint()
{ // JsObject.delete()会执行析构
    std::cout << ">>> MyPoint::~MyPoint()" << std::endl;
}

emscripten::val getBuffer()
{
    std::ostringstream fileStream;
    fileStream << "hello emscripten";
    // ...
    char*  byteBuffer   = strdup(fileStream.str().c_str());
    size_t bufferLength = strlen(byteBuffer);
    return emscripten::val(emscripten::typed_memory_view(bufferLength, byteBuffer));
}

TriangleData* getTriangle(int params)
{
    TriangleData* pData = new TriangleData();
    return pData;
}

emscripten::val getTriangleVertexs(const TriangleData& data)
{
    return emscripten::val::array(data.vertexs.begin(), data.vertexs.end());
}

emscripten::val getTriangleStr(const TriangleData& data)
{
    return emscripten::val::array(data.str.begin(), data.str.end());
}
emscripten::val getTrianglePoint(const TriangleData& data)
{
    return emscripten::val::array(data.points.begin(), data.points.end());
}

} // namespace sindy

EMSCRIPTEN_BINDINGS(sindy)
{
    using namespace sindy;

    // binding function
    emscripten::value_object<Point>("Point").field("x", &Point::x).field("y", &Point::y);

    emscripten::function("_getPoint", &getPoint);
    emscripten::function("_getBuffer", &getBuffer, emscripten::allow_raw_pointers());
    emscripten::function("_getTriangle", &getTriangle, emscripten::allow_raw_pointers());

    // binding class
    emscripten::class_<MyPoint>("MyPoint")
        .constructor<int, const std::string&>()
        .function("incrementX", &MyPoint::incrementX)
        .property("x", &MyPoint::getX, &MyPoint::setX)
        .class_function("getStringFromInstance", &MyPoint::getStringFromInstance);

    // 这种方式不仅把数据导出了，还不侵入TriangleData类的设计!
    emscripten::class_<sindy::TriangleData>("TriangleData")
        .function("_vertexs", &getTriangleVertexs, emscripten::allow_raw_pointers())
        .function("_str", &getTriangleStr, emscripten::allow_raw_pointers())
        .function("_points", &getTrianglePoint, emscripten::allow_raw_pointers());
}
