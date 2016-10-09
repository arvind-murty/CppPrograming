

#include <set>
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

set<string> permutations(string str);

int main()
{
    assert(permutations("ABC") == set<string>({"ABC", "ACB", "BAC", "BCA", "CAB", "CBA"}));
    assert(permutations("AABB") == set<string>({"AABB", "ABAB", "ABBA", "BAAB", "BABA", "BBAA"}));
    return 0;
}

set<string> permutations(string str)
{
    set<string> set1;
    if (str.length() == 1)
    {
        set1.insert(str);
        return set1;
    }
    char ch = str[0];
    str.erase(0, 1);
    set<string> set2 = permutations(str);

    for (string x : set2)
    {
        for (int i = 0; i <= x.length(); ++i)
        {
            string y = x;
            y.insert(i, string("") + ch);
            set1.insert(y);
        }
    }
    return set1;
}
