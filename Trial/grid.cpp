#include "grid.h" //Using " " and not <> because <> checks the header files in standard library but not the folder that the .h file is currently in but " " checks the file inside Trial foler itself
#include <iostream>
#include "colors.h"
using namespace std;

bool Grid::IsRowFull(int row) // This function is used to check whether the row is full or not
{
    for (int column = 0; column < numcols; column++)
    {
        if (grid[row][column] == 0)
        {
            return false;
        }
    }
    return true;
}
void Grid::ClearRow(int row) // This function is clear the row if the isrowfull function returns true
{
    for (int column = 0; column < numcols; column++)
    {
        grid[row][column] = 0;
    }
}
void Grid::MoveRowDown(int row, int numRows) // This function moves down the entire row if the ClearRow function activates
{
    for (int column = 0; column < numcols; column++)
    {
        grid[row + numRows][column] = grid[row][column];
        grid[row][column] = 0;
    }
}
Grid::Grid()
{
    numrows = 20;
    numcols = 10;
    cellsize = 30;
    Initialize();
    colors = GetCellColors();
}
void Grid::Initialize()
{
    for (int row = 0; row < numrows; row++)
    {
        for (int column = 0; column < numcols; column++)
        {
            grid[row][column] = 0;
        }
    }
}
void Grid::Print()
{
    for (int row = 0; row < numrows; row++)
    {
        for (int column = 0; column < numcols; column++)
        {
            cout << grid[row][column] << " ";
        }
        cout << endl;
    }
}
void Grid ::Draw()
{
    for (int row = 0; row < numrows; row++)
    {
        for (int column = 0; column < numcols; column++)
        {
            int cellValue = grid[row][column];
            DrawRectangle(column * cellsize + 11, row * cellsize + 11, cellsize - 1, cellsize - 1, colors[cellValue]);
        }
    }
}

bool Grid::IsCellOutside(int row, int column)
{
    if (row >= 0 && row < numrows && column >= 0 && column < numcols)
    {
        return false;
    }
    return true;
}

bool Grid::IsCellEmpty(int row, int column) // collision for the blocks
{
    if (grid[row][column] == 0)
    {
        return true;
    }
    return false;
}

int Grid::ClearFullRows() // This function will all the rows from bottom to top if any other rows are completed
{
    int completed = 0;
    for (int row = numrows - 1; row >= 0; row--) // This loop checks from bottom to top
    {
        if (IsRowFull(row))
        {
            ClearRow(row);
            completed++;
        }
        else if (completed > 0)
        {
            MoveRowDown(row, completed);
        }
    }
    return completed;
}
