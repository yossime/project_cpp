#include "rational.hpp"

int main()
{
    bool a;
    Rational abc;
    printRational(abc);
    Rational aa(1,2);
    Rational bb(3,4);
    Rational cc = squareRational(bb);
    printRational(cc);
    a = aa.equal(bb);
    aa.multiply(bb);
    printRational(aa);
    std::cout << "double: " << a << '\n';
    aa.add(bb);
    printRational(aa);
    return 0;
}
