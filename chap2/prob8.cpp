

#include <iostream>
using namespace std;


long double permutations(int n, int k);


int main()
{
    int n;
    int k;
    cout << "This program computes the number of ways to pick k objects from n objects." << endl;
    cout << "Enter number of objects: ";
    cin >> n;
    cout << "Enter number of objects chosen from " << n << " objects: ";
    cin >> k;
    long double combinations = permutations(n, k);
    if (combinations > 0)
    {
        cout << "The number of ways to pick " << k << " objects from " << n << " objects is " << combinations << "." << endl;
    }
    else
    {
        cerr << "Impossible permutation entered." << endl;
    }
    return 0;
}


long double permutations(int n, int k)
{
    long double result = 1;
    while (k > 0)
    {
        result *= n;
        --n;
        --k;
    }
    return result;
}
