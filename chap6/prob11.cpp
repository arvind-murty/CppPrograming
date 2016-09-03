
#include <cassert>
#include <iostream>
#include <string>
#include <cstdlib>
#include "tokenscanner.h"
#include "strlib.h"
using namespace std;

int main()
{
    for(;;)
    {
        cout << "> ";
        string str;
        getline(cin, str);
        if (str == "") break;
        TokenScanner scanner(str);

        scanner.addOperator("+");
        scanner.addOperator("-");
        scanner.addOperator("/");
        scanner.addOperator("*");

        scanner.ignoreWhitespace();
        scanner.scanNumbers();

        double value = atof((scanner.nextToken()).c_str());
        while (scanner.hasMoreTokens())
        {
            string op = scanner.nextToken();
            assert (scanner.getTokenType(op) == OPERATOR);

            double subValue = atof((scanner.nextToken()).c_str());
            switch (op[0])
            {
                case '+': value += subValue; break;
                case '-': value -= subValue; break;
                case '*': value *= subValue; break;
                case '/': value /= subValue;
            }
        }
        cout << value << endl;
    }
    return 0;
}
