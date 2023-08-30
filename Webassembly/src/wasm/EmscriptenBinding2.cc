#include "EmscriptenBinding2.h"

#include <emscripten/bind.h>
#include <emscripten/val.h>

#include <sstream>

namespace sindy
{
TriangleData* getTriangleData(int params)
{
    TriangleData* pData = new TriangleData();
    return pData;
}

// "内置类型"可以直接返回
emscripten::val getTriangleVertexs(const TriangleData& data)
{
    return emscripten::val::array(data.vertexs().begin(), data.vertexs().end());
}
emscripten::val getTriangleStr(const TriangleData& data)
{
    return emscripten::val::array(data.strings().begin(), data.strings().end());
}

// 自定义对象要导出，register_vector
std::vector<Point> getTrianglePoint(const TriangleData& data)
{
    return data.points();
}

void initTestObject()
{
    auto object = new EmbindObject(100, 3.14, "obj");
    EmbindManager::instance().add(object);
}
std::vector<EmbindObject*> getTestObject()
{
    auto const& arr = EmbindManager::instance().data();
    return arr; // 调用方可修改指针指向的内存
}
void printFirstObject()
{
    auto const& arr  = EmbindManager::instance().data();
    auto        size = arr.size();
    std::cout << ">>>EmbindManager::instance().data().size() = " << size << std::endl;

    if (size > 0)
        std::cout << ">>>arr[0]->doubleValue() = " << arr[0]->doubleValue() << std::endl;
}

} // namespace sindy

EMSCRIPTEN_BINDINGS(EmscriptenBinding2)
{
    using namespace sindy;

    emscripten::function("_getTestObject", &getTestObject);
    emscripten::function("_initTestObject", &initTestObject);
    emscripten::function("_printFirstObject", &printFirstObject);

    emscripten::function("_getTriangleData", &getTriangleData, emscripten::allow_raw_pointers());

    // 这种方式不仅把数据导出了，还不侵入TriangleData类的设计!
    emscripten::class_<sindy::TriangleData>("TriangleData")
        .function("_vertexs", &getTriangleVertexs, emscripten::allow_raw_pointers())
        .function("_str", &getTriangleStr, emscripten::allow_raw_pointers())
        .function("_points", &getTrianglePoint, emscripten::allow_raw_pointers());

    emscripten::class_<EmbindObject>("EmbindObject")
        .constructor<int, double, std::string const&>()
        .function("intValue", emscripten::select_overload<int() const>(&EmbindObject::intValue))
        .function("intValue", emscripten::select_overload<void(int)>(&EmbindObject::intValue))
        .function("doubleValue", &EmbindObject::doubleValue)
        .function("stringValue", &EmbindObject::stringValue)
        .function("setDouble", &EmbindObject::setDouble)
        .class_function("doIt", &EmbindObject::doIt);

    // 导出vector
    emscripten::register_vector<EmbindObject*>("vector_EmbindObject");
    emscripten::register_vector<Point>("vector_Point");
}
