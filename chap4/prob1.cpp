

#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;


int main()
{
    cout << right;
    cout << " theta | sin(theta) | cos(theta) |" << endl << "-------+------------+------------+" << endl;
    for (double theta = -90; theta <= 90; theta += 15)
    {
        cout << setw(5) << theta << "  |";
        cout << " " << setw(10) << setprecision(7) << sin((theta / 180.0) * M_PI) << " |";
        cout << " " << setw(10) << setprecision(7) << cos((theta / 180.0) * M_PI ) << " |" << endl;
    }
    return 0;
}
