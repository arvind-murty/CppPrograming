

#include "../StanfordCPPLib/StanfordCPPLib/random.h"
#include <iostream>
#include <ctime>
using namespace std;


int main()
{
    double x;
    double y;
    int in_circle = 0;
    setRandomSeed((unsigned) time(NULL));
    for (int i = 0; i < 1000000; i++)
    {
        x = randomReal(-1.0, 1.0);
        y = randomReal(-1.0, 1.0);
        if ((x * x) + (y * y) <= 1)
        {
            ++in_circle;
        }
    }
    double probability = in_circle / 250000.0;
    cout << "The ratio of darts inside the circle to inside the square is " << probability << endl;
    return 0;
}
