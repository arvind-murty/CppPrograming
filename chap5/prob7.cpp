

#include <iostream>
#include "vector.h"
#include "grid.h"
using namespace std;

void fillGrid(Grid<int> & grid, Vector<int> & values);

int main()
{
    Grid<int> matrix(3, 3);
    Vector<int> values;
    values += 1, 2, 3;
    values += 4, 5, 6;
    values += 7, 8, 9;
    fillGrid(matrix, values);
    for (int i = 0; i < matrix.numCols(); ++i)
    {
        for (int j = 0; j < matrix.numRows(); ++j)
        {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}

void fillGrid(Grid<int> & grid, Vector<int> & values)
{
    int columns = grid.numCols();
    int rows = grid.numRows();
    for (int i = 0; i < columns; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            grid.set(j, i, values[i * 3 + j]);
        }
    }
}
