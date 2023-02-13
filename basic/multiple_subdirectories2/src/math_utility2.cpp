#include "math_utility.h"

namespace MathUtility
{
    int sum(int a, int b)
    {
        while (b)
        {
            unsigned int temp = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = temp;
        }
        return a;
    }
}
