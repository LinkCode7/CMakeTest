#include <iostream>
#include "math_utility2.h"

int main()
{
	int left(2), right(3);
	int add = MathUtility::sum(left, right);
	std::cout << "MathUtility::sum(" << left << ", " << right << ") = " << add << std::endl;
	return 0;
}
