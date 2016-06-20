

#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;


int main()
{
    string filename;
    cout << "Input file: ";
    cin >> filename;
    ifstream in;
    in.open(filename.c_str());
    char ch;
    srand((unsigned) time(NULL));

    while (!in.eof())
    {
        in.get(ch);
        if (isalpha(ch))
        {
            if (ch >= 'A' && ch <= 'Z')
            {
                ch = rand() % 26 + 65;
            }
            else
            {
                ch = rand() % 26 + 97;
            }
        }
        cout.put(ch);
    }

    return 0;
}
