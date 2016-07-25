
#include <iostream>
#include "vector.h"
#include "stat.h"
using namespace std;


int main()
{
    Vector<double> data;
    int n;
    for (int i = 0; i < 20; i++)
    {
        cout << "Enter number: ";
        cin >> n;
        data.add(n);
    }
    cout << endl;
    double m = mean(data);
    cout << m << endl;
    return 0;
}
