

#include "rectangle.h"
#include <cassert>
using namespace std;


int main()
{
    Point p;
    assert (p.getX() == 0);
    assert (p.getY() == 0);
    assert (p.toString() == string("(0, 0)"));
    
    Point p1(1, 2);
    assert (p1.getX() == 1);
    assert (p1. getY() == 2);
    assert (p1.toString() == string("(1, 2)"));

    assert (p != p1);
    assert (!(p == p1));
    p = p1;
    assert (p == p1);
    assert (!(p != p1));

    Rectangle r1;
    Rectangle r2(Point(6, 7), 78, 298);
    Rectangle r3(Point(0, 0), 4, 5);
    Rectangle r4(Point (-44, 76), 98, 2);
    Rectangle r5(Point (9, 8), 0, 8);
    Rectangle r6(Point (5, 71), 76, 0);

    assert (r1.getX() == 0);
    assert (r1.getY() == 0);
    assert (r1.getWidth() == 0);
    assert (r1.getHeight() == 0);
    assert (r1.isEmpty());
    assert (!(r1.contains(1, 1)));
    assert (!(r1.contains(0, 0)));
    assert (!(r1.contains(Point(1, 1))));
    assert (!(r1.contains(Point(0, 0))));

    assert (r2.getX() == 6);
    assert (r2.getY() == 7);
    assert (r2.getWidth() == 78);
    assert (r2.getHeight() == 298);
    assert (r2.contains(49, -173));
    assert (!(r2.contains(49, 98)));
    assert (!(r2.contains(147, -173)));
    assert (!(r2.contains(49, -347)));
    assert (!(r2.contains(-57, -173)));
}
