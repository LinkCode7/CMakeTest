#ifndef POINT_H
#define POINT_H
#include "../common.h"

class GEOMETRY_API Point
{
    double m_data[2];

public:
    Point();
    Point(double x, double y);

    void offset(double value);
};

#endif // POINT_H
