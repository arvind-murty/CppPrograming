

#include "../StanfordCPPLib/StanfordCPPLib/random.h"
#include <iostream>
#include <ctime>
using namespace std;


int main()
{
    setRandomSeed((unsigned) time(NULL));
    int i = 0;
    int heads_counter = 0;
    while (heads_counter != 3)
    {
        if (randomChance(0.5))
        {
            cout << "heads" << endl;
            ++heads_counter;
        }
        else
        {
            cout << "tails" << endl;
            heads_counter = 0;
        }
        ++i;
    }
    cout << "It took " << i << " flips to get 3 consecutive heads." << endl;
    return 0;
}
