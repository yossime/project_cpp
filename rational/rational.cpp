#include "rational.hpp"

#include <cassert>

#include <cmath>

Rational::Rational(int num, int denom)
    : m_numerator{num},
      m_denominator{denom}
{
    assert(denom != 0);
    if (denom < 0)
    {
        m_numerator *= -1;
        m_denominator *= -1;
    }
    reduce();
}

Rational::~Rational()
{

}
void Rational::add(class Rational add_nom)
{
    int Commonground;
    add_nom.reduce();
    Commonground = abs((m_denominator * add_nom.m_denominator) / gcd(m_denominator, add_nom.m_denominator));
    m_numerator = (m_numerator * (Commonground / m_denominator)) + (add_nom.m_numerator * (Commonground / add_nom.m_denominator));
    m_denominator = Commonground;
    reduce();
}
bool Rational::equal(class Rational eq_nom)
{
    return double_resolt() == eq_nom.double_resolt();
}
double Rational::double_resolt()
{
    return (double)m_numerator / m_denominator;
}
int Rational::r_numerator()
{
    int num = m_numerator;
    return num;
}
int Rational::r_denominator()
{
    int denom = m_denominator;
    return denom;
}

void Rational::reduce()
{
    int result = gcd(m_numerator, m_denominator);
    m_numerator = m_numerator / result;
    m_denominator = m_denominator / result;
}
void Rational::multiply(class Rational mu_nom)
{
    m_numerator *= mu_nom.m_numerator;
    m_denominator *= mu_nom.m_denominator;
}
void printRational(class Rational rat)
{
    std::cout << "rational number: " << rat.r_numerator() << '/' << rat.r_denominator() << '\n';
}
Rational squareRational(class Rational rat)
{
    return Rational(pow(rat.r_numerator(), 2), pow(rat.r_denominator(), 2));
}

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return abs(a);
}
