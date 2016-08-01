

#include <iostream>
#include "stack.h"
using namespace std;

bool isAligned(string array);

int main()
{
    string array;
    getline (cin, array);
    if (!isAligned(array)) cout << "Improper matching." << endl;
    return 0;
}

bool isAligned(string array)
{
    Stack<char> stack;
    for (int i = 0; array[i] != 0; ++i)
    {
        if (i == 0)
        {
            stack.push(array[i]);
            continue;
        }
        switch (array[i])
        {
            case '{':
            case '[':
            case '(': stack.push(array[i]); break;
            case '}':
                if (stack.pop() != '{') return false;
                break;
            case ']':
                if (stack.pop() != '[') return false;
                break;
            case ')':
                if (stack.pop() != '(') return false;
                break;
        }
    }
    if (stack.isEmpty()) return true;
    return false;
}
