


#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int main()
{
    cout << "This program calculates the value of pi by converting a quarter circle with radius two into rectangles." << endl;
    int i = 1;
    long double width = 2.0 / 10000.0;
    long double midpoint = width / 2.0;
    long double height;
    long double sum = 0;
    while (i <= 10000)
    {
        height = sqrt(4 - (midpoint * midpoint));
        sum += width * height;
        midpoint += width;
        ++i;
    }
    cout << "The value of pi is" << setw(17) << setprecision(15) << sum << endl;
    return 0;
}
