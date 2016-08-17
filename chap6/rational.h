#ifndef _rational_h
#define _rational_h

#include <string>
#include <iostream>

class Rational
{
public:
    Rational();
    Rational(int n);
    Rational(int x, int y);

    int getNum() { return num; };
    int getDen() { return den; };

    std::string toString();

    bool operator==(Rational r);
    bool operator!=(Rational r);
    bool operator<(Rational r);
    bool operator<=(Rational r);
    bool operator>(Rational r);
    bool operator>=(Rational r);

    Rational & operator+=(Rational r);
    Rational & operator-=(Rational r);
    Rational & operator*=(Rational r);
    Rational & operator/=(Rational r);

    Rational & operator++();
    Rational operator++(int);
    Rational & operator--();
    Rational operator--(int);

    Rational & operator=(Rational r);

    friend Rational operator+(Rational r1, Rational r2);
    friend Rational operator-(Rational r1, Rational r2);
    friend Rational operator*(Rational r1, Rational r2);
    friend Rational operator/(Rational r1, Rational r2);

private:
    int num;
    int den;
};

std::ostream & operator<<(std:: ostream & os, Rational rat);
Rational operator+(Rational r1, Rational r2);
Rational operator-(Rational r1, Rational r2);
Rational operator*(Rational r1, Rational r2);
Rational operator/(Rational r1, Rational r2);

#endif
