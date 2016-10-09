

#include <iostream>
using namespace std;

int fact(int n);
int c(int n, int k);

int main()
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            cout << c(i, j) << " ";
        }
        cout << endl;
    }
    return 0;
}

int fact(int n)
{
    return n == 0 ? 1 : n * fact(n - 1);
}

int c(int n, int k)
{
    if (k == 0 || n == 0 || k == n) return 1;
    return c(n - 1, k - 1) + c(n - 1, k);
}
