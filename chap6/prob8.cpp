

#include "rational.h"
#include <cassert>
#include <iostream>
using namespace std;

int main()
{
    Rational rat;
    Rational rat1(4);
    Rational rat2(3, 5);
    Rational rat3(7, 2);

    assert(rat.getNum() == 0);
    assert(rat.getDen() == 1);

    assert(rat1.getNum() == 4);
    assert(rat1.getDen() == 1);

    assert(rat2.getNum() == 3);
    assert(rat2.getDen() == 5);
    assert(rat3.getNum() == 7);
    assert(rat3.getDen() == 2);

    assert(rat.toString() == "0");
    assert(rat1.toString() == "4");
    assert(rat2.toString() == "3/5");
    assert(rat3.toString() == "7/2");

    cout << rat << endl;
    cout << rat1 << endl;
    cout << rat2 << endl;
    cout << rat3 << endl;

    assert(operator+(rat2, rat3).getNum() == 41);
    assert(operator+(rat2, rat3).getDen() == 10);

    assert(operator-(rat2, rat3).getNum() == -29);
    assert(operator-(rat2, rat3).getDen() == 10);

    assert(operator*(rat2, rat3).getNum() == 21);
    assert(operator*(rat2, rat3).getDen() == 10);

    assert(operator/(rat2, rat3).getNum() == 6);
    assert(operator/(rat2, rat3).getDen() == 35);

    assert(rat2.operator==(rat3) == false);
    assert(rat2.operator!=(rat3) == true);

    assert(rat2.operator<(rat3) == true);
    assert(rat2.operator<=(rat3) == true);
    assert(rat2.operator>(rat3) == false);
    assert(rat2.operator>=(rat3) == false);

    assert(rat2.operator+=(rat3).getNum() == 41);
    rat2 = Rational(3, 5);
    assert(rat2.operator+=(rat3).getDen() == 10);
    rat2 = Rational(3, 5);

    assert(rat2.operator-=(rat3).getNum() == -29);
    rat2 = Rational(3, 5);
    assert(rat2.operator-=(rat3).getDen() == 10);
    rat2 = Rational(3, 5);

    assert(rat2.operator*=(rat3).getNum() == 21);
    rat2 = Rational(3, 5);
    assert(rat2.operator*=(rat3).getDen() == 10);
    rat2 = Rational(3, 5);

    assert(rat2.operator/=(rat3).getNum() == 6);
    rat2 = Rational(3, 5);
    assert(rat2.operator/=(rat3).getDen() == 35);
    rat2 = Rational(3, 5);

    assert((++rat2).getNum() == 8);
    rat2 = Rational(3, 5);
    assert((++rat2).getDen() == 5);

    Rational cpy = rat2++;
    assert(cpy.getNum() == 8);
    rat2 = Rational(3, 5);
    assert(rat2++.getDen() == 5);

    rat2 = Rational(3, 5);
    assert((--rat2).getNum() == -2);

    rat2 = Rational(3, 5);
    assert((--rat2).getDen() == 5);

    rat2 = Rational(3, 5);
    cpy = rat2--;
    assert(cpy.getNum()  == 3);
    assert(rat2.getDen() == 5);
    assert(rat2.getNum() == -2);

    rat2 = rat3;
    assert(rat2 == rat3);

    return 0;
}
