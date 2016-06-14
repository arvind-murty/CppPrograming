

#include <string>
#include <cassert>
#include <iostream>
using namespace std;


bool endsWith(string str, string suffix);


int main()
{
    assert (endsWith (string ("foobar"), string ("bar")) == true);
    assert (endsWith (string ("foo"), string ("b")) == false);

    string str;
    string suffix;
    cout << "Enter string: ";
    cin >> str;
    cout << "Enter suffix: ";
    cin >> suffix;

    if (endsWith(str, suffix))
    {
        cout << str << " ends with " << suffix << "." << endl;
    }
    else
    {
        cerr << str << " does not end with " << suffix << "." << endl;
    }

    return 0;
}


bool endsWith(string str, string suffix)
{
    if (suffix.length() > str.length()) return false;

    int i, j;
    for (i = suffix.length() - 1, j = str.length() - 1; i >= 0; i--, j--)
    {
        if (suffix[i] != str[j]) return false;
    }

    return true;
}
