

#include <iostream>
#include "vector.h"
#include "grid.h"
using namespace std;

void fillGrid(Grid<bool> & grid, Vector<bool> & values);
void fixCounts(Grid<bool> & mines, Grid<int> & counts);

int main()
{
    Grid<bool> mineLocations(6, 6);
    Grid<int> mineCounts(6, 6, 0);
    Vector<bool> values;
    values += true, false, false, false, false, true;
    values += false, false, false, false, false, true;
    values += true, true, false, true, false, true;
    values += true, false, false, false, false, false;
    values += false, false, true, false, false, false;
    values += false, false, false, false, false, false;
    fillGrid(mineLocations, values);
    fixCounts(mineLocations, mineCounts);
    for (int i = 0; i < mineCounts.numCols(); ++i)
    {
        for (int j = 0; j < mineCounts.numRows(); ++j)
        {
            cout << mineCounts[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}

void fillGrid(Grid<bool> & grid, Vector<bool> & values)
{
    int columns = grid.numCols();
    int rows = grid.numRows();
    for (int i = 0; i < columns; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            grid.set(j, i, values[i * rows + j]);
        }
    }
}

void fixCounts(Grid<bool> & mines, Grid<int> & counts)
{
    int rows = mines.numRows();
    int cols = mines.numCols();
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (mines[i][j]) ++counts[i][j];
            if (i > 0 && j > 0)
            {
                if (mines[i - 1][j - 1]) ++counts[i][j];
            }
            if (i > 0)
            {
                if (mines[i - 1][j]) ++counts[i][j];
            }
            if (i > 0 && j < cols - 1)
            {
                if (mines[i - 1][j + 1]) ++counts[i][j];
            }
            if (j < cols - 1)
            {
                if (mines[i][j + 1]) ++counts[i][j];
            }
            if (i < rows - 1 && j < cols - 1)
            {
                if (mines[i + 1][j + 1]) ++counts[i][j];
            }
            if (i < rows - 1)
            {
                if (mines[i + 1][j]) ++counts[i][j];
            }
            if (i < rows - 1 && j > 0)
            {
                if (mines[i + 1][j - 1]) ++counts[i][j];
            }
            if (j > 0)
            {
                if (mines[i][j - 1]) ++counts[i][j];
            }
        }
    }
}
