

#include <iostream>
using namespace std;
int MAX_NUM;

bool isPrime(int n);


int main(int argc, char* argv[])
{
    MAX_NUM = argc > 1 && atoi (argv[1]) > 10 ? atoi (argv[1]) : 10;


    cout << "Prime numbers between 1 and " << MAX_NUM << ": " << endl;
    int n = 2;
    while (n <= MAX_NUM)
    {
        if(isPrime(n))
        {
            cout << n << endl;
        }
        ++n;
    }
    return 0;
}


bool isPrime(int n)
{
    if (n == 2)
    {
        return true;
    }
    int i = 2;
    while (i < n)
    {
        if (n % i == 0)
        {
            return false;
        }
        ++i;
    }
    return true;
}
