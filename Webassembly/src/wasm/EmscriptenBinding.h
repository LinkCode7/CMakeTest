#ifndef EMSCRIPTEN_BINDING_H
#define EMSCRIPTEN_BINDING_H
#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace sindy
{
class Point
{
    double _x;
    double _y;

public:
    Point(double xx, double yy);
    ~Point();

    inline double x() const { return _x; }
    inline void   x(double value) { _x = value; }

    inline double y() const { return _y; }
    inline void   y(double value) { _y = value; }

    void multiply(double value)
    {
        _x *= value;
        _y *= value;
    }

    static double getStringFromInstance(const Point& object) { return object._x * object._y; }
};

struct StructObject
{
    int         num;
    double      distance;
    std::string name;
    // StructObject(int num1, double distance1, std::string const& name1) : distance(num1), num(distance1), name(name1) {}
};

} // namespace sindy

#endif // !EMSCRIPTEN_BINDING_H
