

#include <iostream>
using namespace std;

void moveTower(int n, char start, char finish, char tmp);
void moveSingleDisk(char start, char finish);

int main()
{
    moveTower(8, 'A', 'B', 'C');
    return 0;
}

void moveTower(int n, char start, char finish, char tmp)
{
    if (n == 0) return;
    moveTower(n - 1, start, tmp, finish);
    moveSingleDisk(start, finish);
    moveTower(n - 1, tmp, finish, start);
}

void moveSingleDisk(char start, char finish)
{
    cout << start << " -> " << finish << endl;
}
