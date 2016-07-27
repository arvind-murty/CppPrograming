

#include <iostream>
#include "vector.h"
#include "grid.h"
#include "set.h"
using namespace std;

void fillGrid(Grid<int> & grid, Vector<int> & values);
bool checkRow(const Grid<int> & grid, int row);
bool checkCol(const Grid<int> & grid, int col);
bool checkSquare(const Grid<int> & grid, int square);
pair<int, int> coordinate(int square, int num);
bool checkSudokuSolution(Grid<int> & puzzle);

int main()
{
    Grid<int> matrix(9, 9);
    Vector<int> values;
    values += 3, 9, 2, 4, 6, 5, 8, 1, 7;
    values += 7, 4, 1, 8, 9, 3, 6, 2, 5;
    values += 6, 8, 5, 2, 7, 1, 4, 3, 9;
    values += 2, 5, 4, 1, 3, 8, 7, 9, 6;
    values += 8, 3, 9, 6, 2, 7, 1, 5, 4;
    values += 1, 7, 6, 9, 5, 4, 2, 8, 3;
    values += 9, 6, 7, 5, 8, 2, 3, 4, 1;
    values += 4, 2, 3, 7, 1, 9, 5, 6, 8;
    values += 5, 1, 8, 3, 4, 6, 9, 7, 2;
    fillGrid(matrix, values);

    if (checkSudokuSolution(matrix))
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
            grid.set(j, i, values[i * rows + j]);
        }
    }
}

bool checkRow(const Grid<int> & grid, int row)
{
    Set<int> elements;
    for (int col = 0; col < 9; ++col)
    {
        int value = grid[row][col];
        if (elements.contains(value)) return false;
        elements.add(value);
    }
    return true;
}

bool checkCol(const Grid<int> & grid, int col)
{
    Set<int> elements;
    for (int row = 0; row < 9; ++row)
    {
        int value = grid[row][col];
        if (elements.contains(value)) return false;
        elements.add(value);
    }
    return true;
}

bool checkSquare(const Grid<int> & grid, int square)
{
    Set<int> elements;
    for (int num = 0; num < 9; ++num)
    {
        pair<int, int> element = coordinate(square, num);
        int value = grid[element.first][element.second];
        if (elements.contains(value)) return false;
        elements.add(value);
    }
    return true;
}

pair<int, int> coordinate(int square, int num)
{
    int row = (square / 3) * 3 + (num / 3);
    int col = (square % 3) * 3 + (num % 3);
    return make_pair(row, col);
}

bool checkSudokuSolution(Grid<int> & puzzle)
{
    if (puzzle.numRows() != 9) return false;
    if (puzzle.numCols() != 9) return false;

    for (int i = 0; i < 9; ++i)
    {
        if (!checkRow(puzzle, i)) return false;
        if (!checkCol(puzzle, i)) return false;
        if (!checkSquare(puzzle, i)) return false;
    }

    return true;
}
