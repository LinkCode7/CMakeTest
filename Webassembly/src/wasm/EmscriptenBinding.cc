#include "EmscriptenBinding.h"

#include <emscripten/bind.h>
#include <emscripten/val.h>

#include <sstream>

namespace sindy
{
Point::Point(double xx, double yy) : _x(xx), _y(yy)
{ // Js.Module.Point()会执行构造
    std::cout << ">>> Point::Point(double xx, double yy)" << std::endl;
}
Point::~Point()
{ // Js.EmbindObject.delete()会执行析构
    std::cout << ">>> Point::~Point()" << std::endl;
}

Point getPoint()
{
    return Point(100.1, 200.2);
}

StructObject getStructObject()
{
    // StructObject object(10, 10.101, "1010");
    StructObject object;
    object.num      = 10;
    object.distance = 10.101;
    object.name     = "1010";
    return object;
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

} // namespace sindy

EMSCRIPTEN_BINDINGS(EmscriptenBinding)
{
    using namespace sindy;

    emscripten::function("_getPoint", &getPoint);
    emscripten::function("_getStructObject", &getStructObject);

    emscripten::function("_getBuffer", &getBuffer, emscripten::allow_raw_pointers());

    // binding struct
    emscripten::value_object<StructObject>("StructObject")
        .field("num", &StructObject::num)
        .field("distance", &StructObject::distance)
        .field("name", &StructObject::name);

    // binding class:overload function
    emscripten::class_<Point>("Point")
        .constructor<double, double>()
        .function("multiply", &Point::multiply)
        .property("x", emscripten::select_overload<double() const>(&Point::x),
                  emscripten::select_overload<void(double)>(&Point::x))
        .property("y", emscripten::select_overload<double() const>(&Point::y),
                  emscripten::select_overload<void(double)>(&Point::y))
        .class_function("getStringFromInstance", &Point::getStringFromInstance);
}
