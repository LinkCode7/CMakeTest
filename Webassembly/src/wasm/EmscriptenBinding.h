#ifndef EMSCRIPTEN_BINDING_H
#define EMSCRIPTEN_BINDING_H
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
public:
    MyPoint(int x, const std::string& y);
    ~MyPoint();

    void incrementX() { ++x; }

    int  getX() const { return x; }
    void setX(int x_) { x = x_; }

    static std::string getStringFromInstance(const MyPoint& instance) { return instance.y; }

private:
    int         x;
    std::string y;
};

class TriangleData
{
public:
    std::vector<float> vertexs = {1.1, 2.2, 3.3};

    std::vector<std::string> str    = {"msg", "msg"};
    std::vector<MyPoint>     points = {{1, "1"}, {2, "2"}};
    // std::vector<std::shared_ptr<MyPoint>> points = {std::make_shared<MyPoint>(1, "1"), std::make_shared<MyPoint>(2, "2")};

    void test() { vertexs.clear(); }
};

} // namespace sindy

#endif // !EMSCRIPTEN_BINDING_H
