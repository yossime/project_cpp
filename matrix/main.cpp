#include "matrix.hpp"



using namespace Eigen;

int main()
{
    matrix mt1(4);
    mt1 << 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16;
    mt1.print();
    return 0;
}
