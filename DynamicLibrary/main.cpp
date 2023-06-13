#include "main.h"

#include <iostream>

#include "./geometry/common.h"
#include "./geometry/entity/line.h"
#include "./geometry/entity/point.h"

int main()
{
    std::cout << ">>> main()" << std::endl;
    Point pt;
    pt.offset(100);

    Line line({0, 0}, {1, 1});
    line.setBeginPoint({0.5, 0.5});

    utility::func();
    return 0;
}