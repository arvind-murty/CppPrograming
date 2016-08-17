

#include <string>
#include <cstdlib>
#include "error.h"
#include "rational.h"
#include "strlib.h"
using namespace std;

int gcd(int x, int y);

Rational::Rational()
{
    num = 0;
    den = 1;
}

Rational::Rational(int n)
{
    num = n;
    den = 1;
}

Rational::Rational(int x, int y)
{
    if (y == 0) error("Rational: Division by zero");
    if (x == 0)
    {
        num = 0;
        den = 1;
    }
    else
    {
        int g = gcd(abs(x), abs(y));
        num = x / g;
        den = abs(y) / g;
        if (y < 0) num = -num;
    }
}

string Rational::toString()
{
    if (den == 1) return integerToString(num);
    else return integerToString(num) + "/" + integerToString(den);
}

bool Rational::operator==(Rational r)
{
    if (r.num != num) return false;
    if (r.den != den) return false;
    return true;
}

bool Rational::operator!=(Rational r)
{
    return (!this->operator==(r));
}

bool Rational::operator<(Rational r) 
{
    return num * r.den < r.num * den;
}

bool Rational::operator<=(Rational r)
{
    return this->operator<(r) || this->operator==(r);
}

bool Rational::operator>(Rational r) 
{
    return num * r.den > r.num * den;
}

bool Rational::operator>=(Rational r)
{
    return this->operator>(r) || this->operator==(r);
}

Rational & Rational::operator+=(Rational r)
{
    *this = operator+(*this, r);
    return *this;
}

Rational & Rational::operator-=(Rational r)
{
    *this = operator-(*this, r);
    return *this;
}

Rational & Rational::operator*=(Rational r)
{
    *this = operator*(*this, r);
    return *this;
}

Rational & Rational::operator/=(Rational r)
{
    *this = operator/(*this, r);
    return *this;
}

Rational & Rational::operator++()
{
    num += den;
    return *this;
}

Rational Rational::operator++(int)
{
    Rational copy = *this;
    num += den;
    return copy;
}

Rational & Rational::operator--()
{
    num -= den;
    return *this;
}

Rational Rational::operator--(int)
{
    Rational copy = *this;
    num -= den;
    return copy;
}

Rational & Rational::operator=(Rational r)
{
    num = r.num;
    den = r.den;
    return *this;
}

ostream & operator<<(ostream & os, Rational rat)
{
    return os << rat.toString();
}

Rational operator+(Rational r1, Rational r2)
{
    return Rational(r1.num * r2.den + r2.num * r1.den, r1.den * r2.den);
}

Rational operator-(Rational r1, Rational r2)
{
    return Rational(r1.num * r2.den - r2.num * r1.den, r1.den * r2.den);
}

Rational operator*(Rational r1, Rational r2)
{
    return Rational(r1.num * r2.num, r1.den * r2.den);
}

Rational operator/(Rational r1, Rational r2)
{
    return Rational(r1.num * r2.den, r1.den * r2.num);
}

int gcd(int x, int y)
{
    int r = x % y;
    while (r != 0)
    {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}
