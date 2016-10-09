

#include <string>
#include <set>
#include <iostream>
#include <map>
#include <cctype>
#include <fstream>
using namespace std;

map<char, string> mapping({{'1', "1"}, {'2', "ABC"}, {'3', "DEF"}, {'4', "GHI"}, {'5', "JKL"}, {'6', "MNO"}, {'7', "PQRS"}, {'8', "TUV"}, {'9', "WXYZ"}, {'0', "0"}});

set<string> getMnemonics(string str);
string toUpper(string str);
set<string> listMnemonics(string str);

int main()
{
    set<string> set1 = listMnemonics("723");
    for (string x : set1)
    {
        cout << x << endl;
    }
    return 0;
}

set<string> getMnemonics(string str)
{
    set<string> set1;
    if (str.length() == 0)
    {
        set1.insert("");
        return set1;
    }
    char ch = str[0];
    str.erase(0, 1);
    set<string> set2 = getMnemonics(str);
    for (string x : set2)
    {
        for (char y : mapping[ch])
        {
            string z = x;
            z.insert(z.begin(), y);
            set1.insert(z);
        }
    }
    return set1;
}

string toUpper(string str)
{
    string r;
    for (char ch : str)
    {
        r += toupper(ch);
    }
    return r;
}

set<string> listMnemonics(string str)
{
    set<string> set1 = getMnemonics(str);
    ifstream infile;
    infile.clear();
    infile.open("../wordlist.txt");
    set<string> words;
    while (true)
    {
        char z[100];
        infile.getline(z, 100);
        if (infile.eof()) break;
        string s = toUpper(string(z));
        words.insert(s);
    }
    set<string> set2;
    for (string x : set1)
    {
        if (words.find(x) != words.end()) set2.insert(x);
    }
    return set2;
}
