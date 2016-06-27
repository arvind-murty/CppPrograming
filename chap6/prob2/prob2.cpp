

#include "card.h"
#include <iostream>
using namespace std;

Suit& operator++(Suit& s, int)
{
    switch (s)
    {
        case CLUBS:    s = DIAMONDS; break;
        case DIAMONDS: s = HEARTS; break;
        case HEARTS:   s = SPADES; break;
        case SPADES:   s = NONE; break;
        case NONE: break;
    }
    return s;
}

int main()
{
    for (Suit suit = CLUBS; suit <= SPADES; suit++)
    {
        for (int rank = ACE; rank <= KING; rank++)
        {
            cout << " " << Card(suit, rank);
        }
        cout << endl;
    }
    return 0;
}
