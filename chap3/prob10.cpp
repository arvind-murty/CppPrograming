

#include <string>
#include <cassert>
#include <iostream>
using namespace std;


string replaceAll(string str, char c1, char c2);


int main()
{
    assert (replaceAll (string("nannies"), 'n', 'd') == string("daddies"));
    string str;

    char c1;
    char c2;
    cout << "Enter word: ";
    cin >> str;
    cout << "Enter character to be replaced: ";
    cin >> c1;
    cout << "Enter character replacing: ";
    cin >> c2;

    string replaced_str = replaceAll(str, c1, c2);

    cout << "Replaced word is " << replaced_str << "." << endl;

    return 0;
}


string replaceAll(string str, char c1, char c2)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c1)
        {
            str[i] = c2;
        }
    }
    return str;
}
