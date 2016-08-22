

#include <iostream>
#include <fstream>
#include <string>
#include "tokenscanner.h"
#include "set.h"
#include "strlib.h"
using namespace std;

int main()
{
    ifstream infile;
    infile.clear();
    infile.open("wordlist.txt");
    Set<string> words;
    string str;
    while(true)
    {
        getline(infile, str);
        if (infile.eof()) break;
        words.add(str);
    }
    infile.close();
    string filename;
    cout << "Input file: ";
    getline(cin, filename);
    infile.open(filename.c_str());
    if (infile.fail())
    {
        cout << "Error, incorrect filename." << endl;
        return 1;
    }
    TokenScanner sample(infile);
    sample.ignoreWhitespace();
    string token;
    while (sample.hasMoreTokens())
    {
        token = sample.nextToken();
        if (!words.contains(token)) cout << "\"" << token << "\"" << " is not in the dictionary" << endl;
    }
    return 0;
}
