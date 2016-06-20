

#include <string>
#include <cctype>
#include <iostream>
using namespace std;


bool isSentencePalindrome(string str);


int main()
{
    while (true)
    {
        string str;
        cout << "Enter a sentence: ";
        getline(cin, str);
        if (str == "") break;
        if (isSentencePalindrome(str)) cout << "That sentence is a palindrome." << endl;
        else cout << "That sentence is not a palindrome." << endl;
    }
    return 0;
}


bool isSentencePalindrome(string str)
{
    int i = 0;
    int j = str.length() - 1;
    while (i < j)
    {
        while(!isalpha(str[i]))
        {
            ++i;
        }
        while(!isalpha(str[j]))
        {
            --j;
        }
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 'a' - 'A';
        }
        if (str[j] >= 'A' && str[j] <= 'Z')
        {
            str[j] += 'a' - 'A';
        }
        if (str[i] != str[j]) return false;
        ++i;
        --j;
    }
    return true;
}
