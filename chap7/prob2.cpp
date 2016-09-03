

#include <cassert>

int raiseToPower(int n, unsigned int k);

int main()
{
    for (int i = -10; i <= 10; ++i)
    {
        for (int j = 0; j <= 10; ++j)
        {
            int x = 1;
            for (int k = 1; k <= j; ++k)
            {
                x *= i;
            }
            assert(raiseToPower(i, j) == x);
        }
    }
    return 0;
}

int raiseToPower(int n, unsigned int k)
{
    return k == 0 ? 1 : n * raiseToPower(n, k - 1);
}
