#include "line.h"

Line::Line(const Point& begin, const Point& end) : m_ptBegin(begin), m_ptEnd(end)
{
}

void Line::setBeginPoint(const Point& pt)
{
    m_ptBegin = pt;
}