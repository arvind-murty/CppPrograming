#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "point.h"

class Rectangle
{
public:
    Rectangle(Point pt = Point(), int width = 0, int height = 0);

    bool contains(int x, int y);
    bool contains(Point pt);

    int getHeight() { return height; }
    int getWidth() { return width; }
    int getX() { return pt.getX(); }
    int getY() { return pt.getY(); }

    bool isEmpty();

    std::string toString();

private:
    Point pt;
    int width;
    int height;
};

std::ostream & operator<<(std::ostream & os, Rectangle r);

#endif
