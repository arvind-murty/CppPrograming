


#include <iostream>
using namespace std;


int main()
{
    int n;
    cout << "This program factors a number." << endl;
    cout << "Enter number to be factored: ";
    cin >> n;
    int divisor = 2;
    while (n > 1)
    {
        while (n % divisor == 0)
        {
            cout << divisor;
            n /= divisor;
            if (n > 1)
            {
                cout << " * ";
            }
        }
        ++divisor;
    }
    cout << endl;
    return 0;
}
