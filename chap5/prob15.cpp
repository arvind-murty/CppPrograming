

#include <iostream>
#include "stack.h"
#include "vector.h"
using namespace std;

void roll(Stack<char> & stack, int n, int k);

int main()
{
    Stack<char> stack;
    Stack<char> stack1;
    for (char c = 'A'; c <= 'Z'; ++c)
    {
        stack.push(c);
        stack1.push(c);
    }
    roll(stack, 17, 9);
    roll(stack, 17, 8);
    roll(stack1, 26, 52);
    if (stack == stack1)
    {
        return 0;
    }
    cout << "Bad Stuff, Man: Function Is Wrong" << endl;
    return 1;
}

void roll(Stack<char> & stack, int n, int k)
{
    if (n < 0 || k < 0 || n > stack.size())
    {
        cerr << "roll: argument out of range" << endl;
        return;
    }
    Vector<char> vec(n);
    for (int i = n - 1; i >= 0; --i)
    {
        vec[i] = stack.pop();
    }
    for (int temp = 0; temp < k; ++temp)
    {
        for (int i = 0; i < n; ++i)
        {
            char dummy = vec[0];
            vec[0] = vec[i];
            vec[i] = dummy;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        stack.push(vec[i]);
    }
}
