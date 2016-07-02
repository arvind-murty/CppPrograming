

#include "vector.h"
#include "point.h"
#include <iostream>
using namespace std;

int main()
{
    Vector<int> v;

    v.add(3);
    v.add(2);
    v.add(1);

    Vector<int> v2;
    v2.add (2);

    cout << v << " " << v2 << endl;

    v2 = v;
    cout << v << " " << v2 << endl;

    v.add(4);
    v2.add(3);

    cout << v << " " << v2 << endl;
    
    cout << v[1] << endl;

    v[1] = 5;
    cout << v[1] << endl;


    Vector<float> fv;
    fv.add (1.2);
    fv.add (2.1);
    cout << fv << endl;

    Vector<Point> pv;
    pv.add(Point(4,1));
    pv.add(Point(7,4));

    cout << pv << endl;

    return 0;
}
