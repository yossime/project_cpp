#pragma once

#include <iostream>

typedef class Rational
{
public:
    Rational(int num = 0,int denum = 1);
    ~Rational();
    void add(class Rational add_num );
    bool equal(class Rational eq_num);
    double double_resolt();
    int r_numerator();
    int r_denominator(); 
    void multiply(class Rational mu_num);

private:
    void reduce();    

private:
    int m_numerator;
    int m_denominator;
}Rational;

void printRational(class Rational rat);

Rational squareRational(class Rational rat);

int gcd(int a, int b);
