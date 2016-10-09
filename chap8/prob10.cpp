

#include <string>
#include <set>
#include <iostream>
#include <map>
using namespace std;

set<string> listMnemonics(string str);
map<char, string> mapping({{'1', "1"}, {'2', "ABC"}, {'3', "DEF"}, {'4', "GHI"}, {'5', "JKL"}, {'6', "MNO"}, {'7', "PQRS"}, {'8', "TUV"}, {'9', "WXYZ"}, {'0', "0"}});
int main()
{
    set<string> set1 = listMnemonics("723");
    for (string x : set1)
    {
        cout << x << endl;
    }
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
