

#include <iostream>
using namespace std;

int countHanoiMoves(int n);

int main()
{
    for (int i = 1; i <= 10; ++i)
    {
        cout << countHanoiMoves(i) << endl;
    }
    return 0;
}

int countHanoiMoves(int n)
{
    return n == 1 ? 1 : 2 * countHanoiMoves(n - 1) + 1;
}
