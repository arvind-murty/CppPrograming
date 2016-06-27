

#include "domino.h"
using namespace std;


int main()
{
    Domino domino;
    int i = 0;
    int j;
    while (i < 11)
    {
        j = 0;
        while (j < i)
        {
            ++j;
        }
        while (j < 11)
        {
            domino = Domino(i, j);
            cout << domino << endl;
            ++j;
        }
        ++i;
    }
    return 0;
}
