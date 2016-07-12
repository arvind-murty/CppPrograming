
#include <istream>
#include <string>
#include "filelib.h"
#include "xlocale.h"
#include "vector.h"
using namespace std;

void readVector(istream & is, Vector<string> & vec);
void readVector(istream & is, Vector<double> & vec);
void readVector(istream & is, Vector<int> & vec);

int main()
{
    Vector<double> roots;
    ifstream infile;
    promptUserForFile(infile, "Input file: ");
    readVector(infile, roots);
    for(int i = 0; i < roots.size(); i++)
    {
        cout << roots[i] << endl;
    }
    cout << endl;
    roots.clear();
    readVector(infile, roots);
    for(int i = 0; i < roots.size(); i++)
    {
        cout << roots[i] << endl;
    }
    infile.close();
    return 0;
}

void readVector(istream & is, Vector<string> & vec)
{
    string str;
    while (!(is.eof()))
    {
        getline(is, str);
        if (str.length() == 0) break;
        vec.add(str);
    }
}

void readVector(istream & is, Vector<double> & vec)
{
    Vector<string> v;
    readVector(is, v);
    for (int i = 0; i < v.size(); i++)
    {
        vec.add(atof(v[i].c_str()));
    }
}

void readVector(istream & is, Vector<int> & vec)
{
    Vector<string> v;
    readVector(is, v);
    for (int i = 0; i < v.size(); i++)
    {
        vec.add(atoi(v[i].c_str()));
    }
}
