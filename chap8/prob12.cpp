

#include <string>
#include <set>
#include <iostream>
#include <map>
#include <cctype>
#include <fstream>
using namespace std;

map<char, string> mapping({{'1', "1"}, {'2', "ABC"}, {'3', "DEF"}, {'4', "GHI"}, {'5', "JKL"}, {'6', "MNO"}, {'7', "PQRS"}, {'8', "TUV"}, {'9', "WXYZ"}, {'0', "0"}});

set<string> listMnemonics(string str);
string toUpper(string str);
string toLower(string str);
void listCompletions(string str);

int main()
{
    listCompletions("72547");
    return 0;
}

set<string> listMnemonics(string str)
{
    set<string> set1;
    if (str.length() == 0)
    {
        set1.insert("");
        return set1;
    }
    char ch = str[0];
    str.erase(0, 1);
    set<string> set2 = listMnemonics(str);
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
    string x;
    for (char ch : str)
    {
        x += toupper(ch);
    }
    return x;
}

string toLower(string str)
{
    string x;
    for (char ch : str)
    {
        x += tolower(ch);
    }
    return x;
}

void listCompletions(string str)
{
    set<string> set1 = listMnemonics(str);
    ifstream infile;
    infile.clear();
    infile.open("../wordlist.txt");
    set<string> words;
    while (true)
    {
        char c[100];
        infile.getline(c, 100);
        if (infile.eof()) break;
        string s = toUpper(string(c));
        words.insert(s);
    }
    for (string mnemonic : set1)
    {
        for (auto itr = words.lower_bound(mnemonic); itr != words.end(); ++itr)
        {
            string x = *itr;
            if (x.substr(0, mnemonic.length()) == mnemonic)
            {
                string y = toLower(x);
                cout << y << endl;
            }
            else break;
        }
    }
}
