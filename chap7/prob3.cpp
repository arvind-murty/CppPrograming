

#include <cassert>
#include <iostream>
using namespace std;

double getTitiusBodeDistance(unsigned int k);
int getTitiusBodeNumber(unsigned int k);
int main()
{
    for (int i = 1; i < 9; ++i)
    {
        cout << getTitiusBodeDistance(i) << endl;
    }
    return 0;
}

double getTitiusBodeDistance(unsigned int k)
{
    return (4.0 + getTitiusBodeNumber(k)) / 10;
}

int getTitiusBodeNumber(unsigned int k)
{
    if (k == 1) return 1;
    return k == 2 ? 3 : 2 * getTitiusBodeNumber(k - 1);
}
