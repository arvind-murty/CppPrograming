

#include "strlib.h"
#include <string>
#include <iostream>
using namespace std;


string obenglobish(string str);
bool isVowel(char ch);


int main()
{
    while (true)
    {
        string word;
        cout << "Enter a word: ";
        getline(cin, word);
        if (trim(word) == "") break;
        string trans = obenglobish(word);
        cout << word << " -> " << trans << endl;
    }

    return 0;
}


string obenglobish(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (i != 0)
        {
            if (isVowel(str[i - 1]))
            {
            }
            else if (i == str.length() - 1 && str[i] == 'e')
            {
            }
            else if (isVowel(str[i]))
            {   
                str.insert(i, "ob");
                i += 2;
            }
        }
        else if (isVowel(str[i]))
        {
            str.insert(i, "ob");
            i += 2;
        }
    }

    return str;
}


bool isVowel(char ch)
{
    switch (ch)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
    }

    return false;
}
