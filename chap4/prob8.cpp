

#include <fstream>
#include <iostream>
using namespace std;


void removeComments(istream & is, ostream & os);


// Main program
int main()
{
    /*
       Remove comments
     */
    removeComments(cin, cout);
    return 0;
}


void removeComments(istream & is, ostream & os)
{
    char ch;
    char prev_ch = ' ';
    while (!is.eof())
    {
        is.get(ch);
        prev_ch = ch;
        is.get(ch);
        if (prev_ch == '/' && (ch == '/' || ch == '*'))
        {
            if (prev_ch == '/' && ch == '/')
            {
                while (ch != '\n')
                {
                    prev_ch = ch;
                    is.get(ch);
                }
            }

            if (prev_ch == '/' && ch == '*')
            {
                while (!(prev_ch == '*' && ch == '/'))
                {
                    prev_ch = ch;
                    is.get(ch);
                }
            }
        }
        else
        {
            os.put(prev_ch);
            os.put(ch);
            prev_ch = ch;
        }
    }
}
