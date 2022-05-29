#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// A struct to represent a sudoku puzzle
struct Sudoku
{
    int numRows;
    int numCols;
    vector<vector<int>> grid;
};

// Checks if a sudoku puzzle is valid
bool isValid(Sudoku sudoku)
{
    // YOUR CODE HERE
}

// Checks if a sudoku puzzle is solved
bool isSolved(Sudoku sudoku)
{
    // YOUR CODE HERE
}

// Finds a solution for a sudoku puzzle, if one exists
Sudoku solve(Sudoku sudoku)
{
    // YOUR CODE HERE
}

int main()
{
    // Read in the sudoku
    Sudoku sudoku;
    cin >> sudoku.numRows >> sudoku.numCols;

    sudoku.grid.resize(sudoku.numRows);
    for (int i = 0; i < sudoku.numRows; i++)
    {
        sudoku.grid[i].resize(sudoku.numCols);
        for (int j = 0; j < sudoku.numCols; j++)
        {
            cin >> sudoku.grid[i][j];
        }
    }

    // Solve the sudoku
    Sudoku solution = solve(sudoku);

    // Print the solution
    for (int i = 0; i < solution.numRows; i++)
    {
        for (int j = 0; j < solution.numCols; j++)
        {
            cout << solution.grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}