

#include <iostream>
using namespace std;


double square_root(double n);


int main()
{
    double n;
    cout << "This program takes a number and return the square root." << endl << "Enter a number: ";
    cin >> n;
    double sqrt_n = square_root(n);
    cout << "The square root of " << n << " is " << sqrt_n << "." << endl;
    return 0;
}


double square_root(double n)
{
    double g = n / 2;
    double avg = 2;
    while (g != avg)
    {
        g = avg;
        avg = (n / g + g) / 2;
    }
    return avg;
}
