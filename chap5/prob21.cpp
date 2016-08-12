

#include <iostream>
#include <fstream>
#include <string>
#include "map.h"
#include "vector.h"
#include "strlib.h"
using namespace std;

int convertCode(string & name);
Vector<int> codes(string value, Map<int,string> & map);
Map<string,Vector<int>> inverseMap(Map<int,string> & areaCodes);

int main()
{
    ifstream infile;
    infile.clear();
    infile.open("AreaCodes.txt");
    Map<int,string> areaCodes1;
    int key;
    string value;
    string name;
    while (!infile.eof())
    {
        infile >> key;
        if (infile.eof()) break;
        infile.get();
        getline(infile, value);
        areaCodes1.put(key, value);
    }
    Map<string,Vector<int>> areaCodes = inverseMap(areaCodes1);
    Vector<int> vec;
    while (true)
    {
        cout << "Enter area code or state name: ";
        getline(cin, name);
        if (name == "") break;
        if (name[0] > '0' && name[0] <= '9') cout << areaCodes1[convertCode(name)] << endl;
        else
        {
            vec = areaCodes[name];
            for (int i = 0; i < vec.size(); ++i)
            {
                cout << vec[i] << endl;
            }
        }
    }
    return 0;
}


int convertCode(string & name)
{
    return atoi(name.c_str());
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

Map<string,Vector<int>> inverseMap(Map<int,string> & areaCodes)
{
    Map<string,Vector<int>> areaCodes1;
    Vector<string> vec = areaCodes.values();
    for (int i = 0; i < vec.size(); ++i)
    {
        areaCodes1.put(vec[i], codes(vec[i], areaCodes));
    }
    return areaCodes1;
}
