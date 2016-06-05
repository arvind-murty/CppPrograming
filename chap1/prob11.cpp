


#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
    cout << "This program calculates the value of pi using Leibniz's formula." << endl;
    int i = 1;
    long double j = 1;
    long double sum = 0;
    while (i <= 10000)
    {
        sum += 1.0 / j;
        sum -= 1.0 / (j + 2);
        j += 4;
        i += 2;
    }
    sum *= 4;
    cout << "The value of pi is " << setw(17) << setprecision(15) << sum << endl;
    return 0;
}
