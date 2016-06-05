

#include <iostream>
using namespace std;
const int MAX_NUM = 33550337;


bool isPerfect(int n);


int main()
{
    cout << "Perfect numbers between 1 and 9999: " << endl;
    int n = 1;
    while (n < MAX_NUM)
    {
        if (isPerfect(n))
        {
            cout << n << endl;
        }
        ++n;
    }
    return 0;
}


bool isPerfect(int n)
{
    int i = 1;
    int sum_divisors = 0;
    while (i < n && sum_divisors <= n)
    {
        if (n % i == 0)
        {
                sum_divisors += i;
        }
        ++i;
    }
    return sum_divisors == n;
}
