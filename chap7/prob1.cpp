

#include <cassert>

unsigned int cannonball(unsigned int height);

int main()
{
    for (int i = 0; i < 21; ++i)
    {
        int x = 0;
        for (int y = 1; y <= i; ++y)
        {
            x += y * y;
        }
        assert(cannonball(i) == x);
    }
    return 0;
}

unsigned int cannonball(unsigned int height)
{
    return height == 0 ? 0 : height * height + cannonball(height - 1);
}
