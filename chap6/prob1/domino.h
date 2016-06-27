#ifndef DOMINO_H_
#define DOMINO_H_

#include <iostream>
#include <string>

class Domino
{
    int left_dots;
    int right_dots;
    
public:
    Domino();
    Domino(int x, int y);

    std::string toString();

    int getLeftDots();
    int getRightDots();
};

std::ostream & operator<<(std::ostream & os, Domino d);


#endif
