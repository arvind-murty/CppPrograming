

#include <cassert>

int gcd(int x, int y);

int main()
{
    assert(gcd(48, 36) == 12);
    assert(gcd(60, 7) == 1);
    assert(gcd(192, 60) == 12);
    return 0;
}

int gcd(int x, int y)
{
    return x % y == 0 ? y : gcd(y, x % y);
}
