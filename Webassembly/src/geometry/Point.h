#ifndef POINT_H
#define POINT_H

class Point
{
public:
    double x;
    double y;

    Point() : x(0.0), y(0.0) {}
    Point(double xx, double yy) : x(xx), y(yy) {}

    Point operator+(double value) { return {x + value, y + value}; }
};

#endif // !POINT_H
