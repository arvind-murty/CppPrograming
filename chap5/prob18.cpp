

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "grid.h"
using namespace std;

int main()
{
    Grid<bool> grid(25, 25, true);
    int ballsInAir[5] = {1, 0};
    int ballInAir = 1;
    int highBallsInAir = 1;
    int timeElapsed = 1;
    int num = 2;
    srand((unsigned) time(NULL));
    grid[rand() % 25][rand() % 25] = false;
    while (ballInAir != 0)
    {
        for (int i = 0; i < 4; ++i)
        {
            ballsInAir[i] = ballsInAir[i + 1];
        }
        ballsInAir[4] = 0;
        for (int i = 0; i < ballsInAir[0]; ++i)
        {
            int j = rand() % 25;
            int k = rand() % 25;
            if (grid[j][k] == true)
            {
                num += 2;
                grid[j][k] = false;
            }
        }
        for (int i = 0; i < num; ++i)
        {
            int rep = rand() % 4 + 1;
            ++ballsInAir[rep];
        }
        ballInAir = ballsInAir[1] + ballsInAir[2] + ballsInAir[3] + ballsInAir[4];
        highBallsInAir = ballInAir > highBallsInAir ? ballInAir : highBallsInAir;
        num = 0;
        ++timeElapsed;
    }
    double trapSprung = 0;
    for (int i = 0; i < 25; ++i)
    {
        for (int j = 0; j < 25; ++j)
        {
            if (grid[i][j] == false) ++trapSprung;
        }
    }
    cout << "Time units that have elapsed: " << timeElapsed << endl;
    cout << "Percentage of traps that have been sprung: " << trapSprung << " / 625 or ";
    trapSprung /= 6.25;
    cout << trapSprung << "%" << endl;
    cout << "Maximum number of balls in the air: " << highBallsInAir << endl;
    return 0;
}
