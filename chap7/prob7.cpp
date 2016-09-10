

#include <cassert>

int digitSum(int n);

int main()
{
    for (int i = 0; i < 5000; ++i)
    {
        assert(digitSum(i) + digitSum(9999 - i) == 36);
    }
    return 0;
}

int digitSum(int n)
{
    if (n / 10 == 0) return n;
    return digitSum(n / 10) + digitSum(n % 10);
}
