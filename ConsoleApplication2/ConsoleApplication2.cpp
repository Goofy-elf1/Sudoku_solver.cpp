#include <iostream>
#include <vector>

using namespace std;

// Function to check if placing 'num' in grid[row][col] is valid
bool isValid(vector<vector<int>>& grid, int row, int col, int num) {
    // Check if 'num' is not present in the current row and column
    for (int i = 0; i < 9; ++i) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    // Check if 'num' is not present in the 3x3 sub-grid
    int startRow = 3 * (row / 3);
    int startCol = 3 * (col / 3);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

// Backtracking function to solve the Sudoku puzzle
bool solveSudoku(vector<vector<int>>& grid) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            // If the cell is empty (denoted by 0)
            if (grid[row][col] == 0) {
                // Try all numbers from 1 to 9
                for (int num = 1; num <= 9; ++num) {
                    if (isValid(grid, row, col, num)) {
                        // Place the number if it's valid
                        grid[row][col] = num;

                        // Recursively attempt to solve the rest of the puzzle
                        if (solveSudoku(grid)) {
                            return true; // Puzzle solved
                        }

                        // Backtrack: Reset the cell to 0 if no solution found
                        grid[row][col] = 0;
                    }
                }
                return false; // Trigger backtracking
            }
        }
    }
    return true; // Puzzle is solved
}

// Utility function to print the Sudoku grid
void printGrid(const vector<vector<int>>& grid) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example Sudoku grid (0 represents empty cells)
    vector<vector<int>> grid = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(grid)) {
        cout << "Sudoku Solved Successfully!" << endl;
        printGrid(grid);
    }
    else {
        cout << "No solution exists." << endl;
    }

    return 0;
}