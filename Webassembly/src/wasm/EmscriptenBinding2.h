#ifndef EMSCRIPTEN_BINDING2_H
#define EMSCRIPTEN_BINDING2_H
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "EmscriptenBinding.h"

namespace sindy
{
class TriangleData
{
    std::vector<float>       _vertexs = {1.1, 2.2, 3.3};
    std::vector<std::string> _strings = {"msg", "msg"};
    std::vector<Point>       _points  = {{1, 1}, {2, 2}};

public:
    const std::vector<float>&       vertexs() const { return _vertexs; }
    const std::vector<std::string>& strings() const { return _strings; }
    const std::vector<Point>&       points() const { return _points; }

    // std::vector<std::shared_ptr<Point>> points = {std::make_shared<Point>(1, "1"), std::make_shared<Point>(2, "2")};

    void test() { _vertexs.clear(); }
};

// Simulation example
class EmbindObject
{
    int         _int;
    double      _double;
    std::string _string;

    Point _pt;

public:
    EmbindObject(int i, double d, std::string const& s) : _int(i), _double(d), _string(s), _pt(1.21, 6.123456789) {}

    int intValue() const
    {
        std::cout << "int EmbindObject::intValue() const\n";
        return _int;
    }
    void intValue(int value)
    {
        std::cout << "void EmbindObject::intValue(int)\n";
        _int = value;
    }

    double      doubleValue() const { return _double; }
    std::string stringValue() const { return _string; }

    void setDouble(double value) { _double = value; }

    static void doIt() { std::cout << "EmbindObject" << std::endl; }
};
class EmbindManager
{
    std::vector<EmbindObject*> _data;
    EmbindManager() {}

public:
    static EmbindManager& instance()
    {
        static EmbindManager opr;
        return opr;
    }

    void add(EmbindObject* object) { _data.emplace_back(object); }

    std::vector<EmbindObject*> data() const { return _data; }
};

} // namespace sindy

#endif // !EMSCRIPTEN_BINDING2_H
