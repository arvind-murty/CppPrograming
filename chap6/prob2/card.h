#ifndef CARD_H_
#define CARD_H_

#include <string>
#include <ostream>

enum Suit 
{
    CLUBS = 0,
    DIAMONDS,
    HEARTS,
    SPADES,
    NONE
};


const int ACE   = 1;
const int JACK  = 11;
const int QUEEN = 12;
const int KING  = 13;



class Card
{
public:
    Card (Suit suit = CLUBS, int rank = ACE);
    Card (const std::string& str);

    void set (Suit suit, int rank);

    Suit getSuit ();
    int  getRank ();

    std::string toString() const;

private:
    void setSuit(char c);

    Suit suit;
    int  rank;
};

std::ostream& operator<< (std::ostream& os, const Card& c);

#endif

