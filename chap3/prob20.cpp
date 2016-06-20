

#include <string>
#include <iostream>
using namespace std;


int findDNAMatch(string s1, string s2);


int main()
{
    string str1, str2;
    cout << "Enter longer DNA sequence (capital A, G, C, T): ";
    cin >> str2;
    cout << "Enter shorter DNA sequence (capital A, G, C, T): ";
    cin >> str1;
    int match = findDNAMatch(str1, str2);
    if (match != -1)
    {
        cout << "The two sequences match at position " << match << "." << endl;
    }
    else
    {
        cerr << "The two sequences did not match." << endl;
    }
    return 0;
}


int findDNAMatch(string s1, string s2)
{
    int i = 0;
    while (i < s2.length())
    {
        switch (s2[i])
        {
            case 'A':
                s2[i] = 'T';
                break;
            case 'T':
                s2[i] = 'A';
                break;
            case 'C':
                s2[i] = 'G';
                break;
            case 'G':
                s2[i] = 'C';
                break;
        }
        ++i;
    }
    if (s2.find(s1) == string::npos)
    {
        return -1;
    }
    
    return s2.find(s1);
}
