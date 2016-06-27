


#include <string>
#include "domino.h"
#include "strlib.h"
using namespace std;

Domino::Domino()
{
    left_dots = 0;
    right_dots = 0;
}

Domino::Domino(int x, int y)
{
    left_dots = x;
    right_dots = y;
}

string Domino::toString()
{
    return integerToString(left_dots) + "-" + integerToString(right_dots);
}

int Domino::getLeftDots()
{
    return left_dots;
}

int Domino::getRightDots()
{
    return right_dots;
}

ostream & operator<<(ostream & os, Domino d)
{
    string str = d.toString();
    os << str;
    return os;
}
