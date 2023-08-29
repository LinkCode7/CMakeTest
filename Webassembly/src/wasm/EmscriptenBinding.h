#ifndef EMSCRIPTEN_BINDING_H
#define EMSCRIPTEN_BINDING_H
#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace sindy
{
struct Point
{
    int x;
    int y;
};

Point getPoint()
{
    Point point = {100, 200};
    return point;
}

class MyPoint
{
    double _x;
    double _y;

    std::string _str;

public:
    MyPoint(double xx, double yy, std::string const& str);
    ~MyPoint();

    inline int  x() const { return _x; }
    inline void x(double value) { _x = value; }

    inline double y() const { return _y; }
    inline void   y(double value) { _y = value; }

    // 内联调用
    inline int    getX() const { return x(); }
    inline void   setX(double value) { x(value); }
    inline double getY() const { return y(); }
    inline void   setY(double value) { y(value); }

    void resetX(double value) { _x = value; }

    static std::string getStringFromInstance(const MyPoint& object) { return object._str; }
};

class TriangleData
{
public:
    std::vector<float> vertexs = {1.1, 2.2, 3.3};

    std::vector<std::string> str    = {"msg", "msg"};
    std::vector<MyPoint>     points = {{1, 1, "1"}, {2, 2, "2"}};
    // std::vector<std::shared_ptr<MyPoint>> points = {std::make_shared<MyPoint>(1, "1"), std::make_shared<MyPoint>(2, "2")};

    void test() { vertexs.clear(); }
};

} // namespace sindy

class EmbindObject
{
    int         _int;
    double      _double;
    std::string _string;

    sindy::MyPoint _pt;

public:
    EmbindObject(int i, double d, std::string const& s) : _int(i), _double(d), _string(s), _pt(1.21, 6.123456789, "point") {}

    int intValue() const { return _int; }
    // void intValue(int value) { _int = value; }

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
#endif // !EMSCRIPTEN_BINDING_H
