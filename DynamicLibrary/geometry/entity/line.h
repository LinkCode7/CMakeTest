#ifndef LINE_H
#define LINE_H
#include "point.h"

class GEOMETRY_API Line
{
    Point m_ptBegin;
    Point m_ptEnd;

public:
    Line(const Point& begin, const Point& end);

    void setBeginPoint(const Point& pt);
};

#endif // LINE_H
