

#include <iostream>
#include "vector.h"
#include "grid.h"
using namespace std;

bool isMagicSquare(Grid<int> & grid);
void fillGrid(Grid<int> & grid, Vector<int> & values);

int main()
{
    Grid<int> matrix(3, 3);
    Vector<int> values;
    values += 8, 1, 5;
    values += 3, 5, 7;
    values += 4, 9, 2;
    fillGrid(matrix, values);
    if (isMagicSquare(matrix))
    {
        for (int i = 0; i < matrix.numCols(); ++i)
        {
            for (int j = 0; j < matrix.numRows(); ++j)
            {
                cout << matrix[j][i] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "This grid is not a magic square." << endl;
    }

    return 0;
}

bool isMagicSquare(Grid<int> & grid)
{
    Vector<int> rows;
    Vector<int> columns;
    Vector<int> diagnols;
    int row_sum = 0;
    int column_sum = 0;
    int diagnol_sum = 0;

    if (grid.numRows() != grid.numCols()) return false;

    for (int i = 0; i < grid.numRows(); ++i)
    {
        row_sum = 0;
        column_sum = 0;
        for (int j = 0; j < grid.numCols(); ++j)
        {
            row_sum += grid[i][j];
            column_sum += grid[j][i];
        }
        rows.add(row_sum);
        columns.add(column_sum);
    }
    for (int i = 0, j = 0; i < grid.numRows(); ++i, ++j)
    {
        diagnol_sum += grid[i][j];
    }
    diagnols.add(diagnol_sum);
    diagnol_sum = 0;
    for (int i = 0, j = grid.numCols() - 1; i < grid.numRows(); ++i, --j)
    {
        diagnol_sum += grid[i][j];
    }
    diagnols.add(diagnol_sum);

    for (int i = 0; i < grid.numRows() - 1; ++i)
    {
        if (rows[i] != rows[i + 1]) return false;
        if (columns[i] != columns[i + 1]) return false;
    }
    if (diagnols[0] != diagnols [1]) return false;
    if (rows[0] != columns[0]) return false;
    if (columns[0] != diagnols[0]) return false;

    return true;
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
