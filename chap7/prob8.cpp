

#include <cassert>

int digitSum(int n);
int digitalRoot(int n);

int main()
{
    assert(digitalRoot(1729) == 1);
    for (int i = 1; i <= 5000; ++i)
    {
        assert(digitalRoot(i * 9) == 9);
    }
    return 0;
}

int digitSum(int n)
{
    if (n / 10 == 0) return n;
    return digitSum(n / 10) + digitSum(n % 10);
}

int digitalRoot(int n)
{
    if (n / 10 == 0) return n;
    return digitalRoot(digitSum(n));
}
