

#include "point.h"
#include "strlib.h"
using namespace std;

Point::Point(int xc, int yc)
{
    x = xc;
    y = yc;
}

Point & Point::operator=(Point pt)
{
    x = pt.getX();
    y = pt.getY();
    return *this;
}

string Point::toString()
{
    return "(" + integerToString(x) + ", " + integerToString(y) + ")";
}

bool operator==(Point p1, Point p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}

bool operator!=(Point p1, Point p2)
{
    return !(p1 == p2);
}

ostream & operator<<(ostream & os, Point p)
{
    return os << p.toString();
}
