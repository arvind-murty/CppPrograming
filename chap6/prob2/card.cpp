

#include "card.h"




Card::Card (Suit suit, int rank)
{
    this->suit = suit;
    this->rank = rank;
}



Card::Card (const std::string& str)
{
    if (str.length() == 3)
    {
        rank = 10;
        setSuit (str[2]);
    }
    else
    {
        setSuit(str[1]);
        switch (str[0])
        {
            case 'A':
                rank = ACE;
                break;
            case '2':
                rank = 2;
                break;
            case '3':
                rank = 3;
                break;
            case '4':
                rank = 4;
                break;
            case '5':
                rank = 5;
                break;
            case '6':
                rank = 6;
                break;
            case '7':
                rank = 7;
                break;
            case '8':
                rank = 8;
                break;
            case '9':
                rank = 9;
                break;
            case 'J':
                rank = JACK;
                break;
            case 'Q':
                rank = QUEEN;
                break;
            default :
                rank = KING;
        }
    }
}

void Card::setSuit (char c)
{ 
    switch (c)
    {
        case 'C':
            suit = CLUBS;
            break;
        case 'D':
            suit = DIAMONDS;
            break;
        case 'H':
            suit = HEARTS;
            break;
        default :
            suit = SPADES;
    }
}

void Card::set (Suit suit, int rank)
{
    this->suit = suit;
    this->rank = rank;
}

Suit Card::getSuit ()
{
    return suit;
}
int  Card::getRank ()
{
    return rank;
}


std::string Card::toString() const
{
    std::string str;
    const char* rankToChar = "0A234567891JQK";
    const char* suitToChar = "CDHS";
    str += rankToChar[rank];
    if (rank == 10) str += '0';
    str += suitToChar[suit];
    return str;
            
}

std::ostream& operator<< (std::ostream& os, const Card& c)
{
    std::string str = c.toString();
    os << str;
    return os;
}
