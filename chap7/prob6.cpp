

#include <iostream>
using namespace std;

int countFib1(int n);
int countFib2(int n);

int main()
{
    cout << "This program counts the number of calls made by the two" << endl;
    cout << "algorithms used to compute the Fibonacci sequence." << endl << endl;
    for (int i = 0; i <= 12; ++i)
    {
        cout << "    " << i << "    " << countFib1(i) << "     " << countFib2(i) << endl;
    }
    return 0;
}

int countFib1(int n)
{
    if (n < 2) return 1;
    return countFib1(n - 1) + countFib1(n - 2) + 1;
}

int countFib2(int n)
{
    if (n < 2) return 2;
    return countFib2(n - 1) + 1;
}
