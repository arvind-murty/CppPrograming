

#include <iostream>
#include <cmath>
using namespace std;
const int MAX_NUM = 33550337;


bool isPerfect(int n);


int main()
{
    cout << "Perfect numbers between 1 and 33550336: " << endl;
    int n = 2;
    while (n < MAX_NUM)
    {
        if (n % 1000000 == 0)
        {
            cout << n << " and counting." << endl;
        }
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
    while (i <= sqrt(n) && sum_divisors <= n)
    {
        if (i == sqrt(n))
        {
            sum_divisors += i;
        }
        else
        {
            if (n % i == 0)
            {
                sum_divisors += i;
                if (i != 1)
                {
                    sum_divisors += n / i;
                }
            }
        }
        ++i;
    }
    return sum_divisors == n;
}
