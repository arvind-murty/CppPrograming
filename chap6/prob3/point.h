#ifndef POINT_H_
#define POINT_H_

#include <string>
#include <ostream>
#include <iostream>

class Point
{
public:
    Point(int xc = 0, int yc = 0);

    int getX() { return x; }
    int getY() { return y; }

    Point & operator=(Point pt);

    std::string toString();

private:
    friend bool operator==(Point p1, Point p2);
    
    int x;
    int y;
};

std::ostream & operator<<(std::ostream & os, Point p);

bool operator==(Point p1, Point p2);

bool operator!=(Point p1, Point p2);

#endif
