

#include "rectangle.h"
#include "strlib.h"
#include "iostream"
using namespace std;

Rectangle::Rectangle(Point pt, int width, int height)
{
    this->pt = pt;
    this->width = width;
    this->height = height;
}

bool Rectangle::contains(int x, int y)
{
    return x > getX() && y < getY() && x < getX() + width && y > getY() - height;
}

bool Rectangle::contains(Point p)
{
    return contains(p.getX(), p.getY());
}

bool Rectangle::isEmpty()
{
    return width * height == 0;
}

string Rectangle::toString()
{
    return "(" + integerToString(getX()) + ", " + integerToString(getY()) + ", " + integerToString(width) + ", " + integerToString(height) + ")";
}

ostream & operator<<(ostream & os, Rectangle r)
{
    return os << r.toString();
}
