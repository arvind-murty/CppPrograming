

#include "set.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

void embeddedWords(Set<string> & set, string word, Set<string> & dictionary);

int main()
{
    ifstream infile;
    infile.clear();
    infile.open("../wordlist.txt");
    Set<string> wordlist;
    while (!infile.eof())
    {
        char str[1000];
        infile.getline(str,1000);
        wordlist.add(string(str));
    }
    cout << "Enter starting word: ";
    string word;
    cin >> word;
    cout << "The embedded words are: " << endl;
    Set<string> set;
    embeddedWords(wordlist, word, set);
    cout << set << endl;
    return 0;
}

void embeddedWords(Set<string> & set, string word, Set<string> & dictionary)
{
    if (set.contains(word))
    {
        dictionary.add(word);
    }
    if (word.length() == 1) return;
    for (int i = 0; i < word.length(); ++i)
    {
        char letter = word[i];
        string rest = word.substr(0, i) + word.substr(i + 1, string::npos);
        embeddedWords(set, rest, dictionary);
    }
}
