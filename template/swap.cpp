#include "swap.hpp"

#include <iostream>
#include "generics.hpp"

void test_swap()
{
    int x = 4;
    int y = 9;
    swap(x, y);
    std::cout << x << " " << y << std::endl;

    double pi = 3.141592653589793238;
    double e = 2.718281828459045235;
    swap<double>(pi, e);
    std::cout << pi << " " << e << std::endl;
}
