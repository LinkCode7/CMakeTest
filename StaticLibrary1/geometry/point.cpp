#include "point.h"

Point::Point()
{
    m_data[0] = 0.0;
    m_data[1] = 0.0;
}

Point::Point(double x, double y)
{
    m_data[0] = x;
    m_data[1] = y;
}