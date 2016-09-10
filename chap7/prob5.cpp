

#include <iostream>
using namespace std;

int fib(int n);

int main()
{
    for (int i = 0; i <= 45; ++i)
    {
        cout << fib(i) << endl;
    }
    return 0;
}

int fib(int n)
{
    int value = 1;
    int orgvalue = 1;
    int prevalue = 1;
    for (int i = 2; i <= n; ++i)
    {
        prevalue = orgvalue;
        orgvalue = value;
        value += prevalue;
    }
    return value;
}
