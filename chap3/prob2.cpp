

#include <string>
#include <cctype>
#include <cassert>
#include <iostream>
using namespace std;


string trim(string str);


int main()
{
    assert (trim (string (" abc def ")) == string ("abc def"));
    assert (trim (string ("     abc def     ")) == string ("abc def"));

    string str;
    cout << "Enter sentence: ";
    getline(cin, str);
    cout << ":" << str << ":" << endl;
    string trimmed_str = trim(str);
    cout << ":" <<  trimmed_str  << ":" << endl;

    return 0;
}


string trim(string str)
{
    while (isspace(str[0]))
    {
        str.erase(0, 1);
    }

    for (int i = str.length() - 1; isspace(str[i]); i--)
    {
        str.erase(i, 1);
    }
    return str;
}
