

#include <iostream>
#include <fstream>
#include <string>
#include "map.h"
#include "vector.h"
#include "strlib.h"
using namespace std;

Vector<int> codes(string value, Map<int,string> & map);
int convertCode(string & name);

int main()
{
    ifstream infile;
    infile.clear();
    infile.open("AreaCodes.txt");
    Map<int,string> areaCodes;
    int key;
    string value;
    string name;
    while (!infile.eof())
    {
        infile >> key;
        if (infile.eof()) break;
        infile.get();
        getline(infile, value);
        areaCodes.put(key, value);
    }
    Vector<int> vec;
    while (true)
    {
        cout << "Enter area code or state name: ";
        getline(cin, name);
        if (name == "") break;
        if (name[0] > '0' && name[0] <= '9') cout << areaCodes[convertCode(name)] << endl;
        else
        {
            vec = codes(name, areaCodes);
            for (int i = 0; i < vec.size(); ++i)
            {
                cout << vec[i] << endl;
            }
        }
    }
    return 0;
}

Vector<int> codes(string value, Map<int,string> & map)
{
    Vector<int> vec = map.keys();
    for (int i = 0; i < vec.size();)
    {
        if (map[vec[i]] != value) vec.remove(i);
        else ++i;
    }
    return vec;
}

int convertCode(string & name)
{
    return atoi(name.c_str());
}
