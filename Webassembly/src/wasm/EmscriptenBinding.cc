#include "EmscriptenBinding.h"

#include <emscripten/bind.h>
#include <emscripten/val.h>

#include <iostream>
#include <sstream>

namespace sindy
{
MyPoint::MyPoint(double xx, double yy, std::string const& str) : _x(xx), _y(yy), _str(str)
{ // Js.Module.MyPoint()会执行构造
    std::cout << ">>> MyPoint::MyPoint(double xx, double yy, const std::string& str)" << std::endl;
}
MyPoint::~MyPoint()
{ // Js.EmbindObject.delete()会执行析构
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

TriangleData* getTriangleData(int params)
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

std::vector<EmbindObject> g_objects;

void printFirstObject()
{
    auto const& arr  = EmbindManager::instance().data();
    auto        size = arr.size();
    std::cout << ">>>EmbindManager::instance().data().size() = " << size << std::endl;

    if (size > 0)
        std::cout << ">>>arr[0]->doubleValue() = " << arr[0]->doubleValue() << std::endl;
}
std::vector<EmbindObject*> getTestObject()
{
    auto object = new EmbindObject(100, 3.14, "obj");
    EmbindManager::instance().add(object);

    auto const& arr = EmbindManager::instance().data();

    g_objects.clear();
    for (auto const& pObject : arr)
        g_objects.emplace_back(*pObject);

    return arr;
    // return emscripten::val::array(g_objects.begin(), g_objects.end());
}

EMSCRIPTEN_BINDINGS(sindy)
{
    using namespace sindy;

    emscripten::function("_getTestObject", &getTestObject);
    emscripten::function("_printFirstObject", &printFirstObject);

    // binding function
    emscripten::value_object<Point>("Point").field("x", &Point::x).field("y", &Point::y);

    emscripten::function("_getPoint", &getPoint);
    emscripten::function("_getBuffer", &getBuffer, emscripten::allow_raw_pointers());
    emscripten::function("_getTriangleData", &getTriangleData, emscripten::allow_raw_pointers());

    // binding class
    emscripten::class_<MyPoint>("MyPoint")
        .constructor<double, double, std::string const&>()
        .function("resetX", &MyPoint::resetX)
        .function("getX", &MyPoint::getX)
        .function("setX", &MyPoint::setX)
        .function("getY", &MyPoint::getY)
        .function("setY", &MyPoint::setY)
        .class_function("getStringFromInstance", &MyPoint::getStringFromInstance);

    // 这种方式不仅把数据导出了，还不侵入TriangleData类的设计!
    emscripten::class_<sindy::TriangleData>("TriangleData")
        .function("_vertexs", &getTriangleVertexs, emscripten::allow_raw_pointers())
        .function("_str", &getTriangleStr, emscripten::allow_raw_pointers())
        .function("_points", &getTrianglePoint, emscripten::allow_raw_pointers());

    emscripten::class_<EmbindObject>("EmbindObject")
        .constructor<int, double, std::string const&>()
        .function("intValue", &EmbindObject::intValue)
        .function("doubleValue", &EmbindObject::doubleValue)
        .function("stringValue", &EmbindObject::stringValue)
        .function("setDouble", &EmbindObject::setDouble)
        .class_function("doIt", &EmbindObject::doIt);

    emscripten::register_vector<EmbindObject*>("vector_EmbindObject");
}
