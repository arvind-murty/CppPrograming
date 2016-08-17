

#include <iostream>
#include <cctype>
#include <string>
#include "stack.h"
#include "rational.h"
using namespace std;

int main()
{
    cout << "RPN Calculator Simulation (type H for help)" << endl;
    Rational x, y, z;
    string str;
    Stack<Rational> stack;
    while (true)
    {
        cout << "> ";
        cin >> str;
        if (str == "H")
        {
            cout << "Enter expressions in Reverse Polish Notation," << endl;
            cout << "in which operators follow the operands to which" << endl;
            cout << "they apply.  Each line consists of a number, an" << endl;
            cout << "operator, or one of the following commands:" << endl;
            cout << "  Q -- Quit the program" << endl;
            cout << "  H -- Display this help message" << endl;
            cout << "  C -- Clear the calculator stack" << endl;
        }
        else if (str == "Q") break;
        else if (str == "C") stack.clear();
        else if (str[0] >= '0' && str[0] <= '9') stack.push(Rational(atoi(str.c_str()), 1));
        else
        {
            y = stack.pop();
            x = stack.pop();
            switch (str[0])
            {
                case '+': z = x + y; break;
                case '-': z = x - y; break;
                case '*': z = x * y; break;
                case '/': z = x / y;
            }
            cout << z << endl;
            stack.push(z);
        }
    }
    return 0;
}
