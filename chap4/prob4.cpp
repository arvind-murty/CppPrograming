

#include <fstream>
#include <string>
#include <iostream>
using namespace std;


int main()
{
    string filename;
    cout << "Input file: ";
    cin >> filename;
    ifstream in;
    in.open(filename.c_str());
    char prev_ch, ch = ' ';
    int characters = -1, words = 0, lines = -1;

    while(!in.eof())
    {
        prev_ch = ch;
        in.get(ch);
        if (isspace(ch) && !isspace(prev_ch)) ++words;
        if (ch == '\n') ++lines;
        ++characters;
    }

    cout << "Chars: " << characters << endl;
    cout << "Words: " << words << endl;
    cout << "Lines: " << lines << endl;

    return 0;
}
