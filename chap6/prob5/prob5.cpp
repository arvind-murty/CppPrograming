

#include "calendar.h"
#include <cassert>
#include <iostream>
using namespace std;


int main()
{
    Date moonLanding(20, JUL, 1969);

    assert(moonLanding.getDay() == 20);
    assert(moonLanding.getMonth() == JUL);
    assert(moonLanding.getYear() == 1969);
    assert(moonLanding.toString() == "20-Jul-1969");

    return 0;
}
