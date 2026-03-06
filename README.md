# 🧩 Sudoku Solver — C++

A clean, efficient Sudoku solver written in C++ using a **backtracking algorithm**. Give it a puzzle with empty cells and it'll find the solution — or tell you none exists.

---

## 🚀 Getting Started

### Compile

```bash
g++ -o sudoku sudoku.cpp
```

### Run

```bash
./sudoku
```

### Expected Output

```
Sudoku Solved Successfully!
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
```

---

## 🧠 How It Works

The solver uses **recursive backtracking** — a classic constraint satisfaction approach:

1. Scan the grid left-to-right, top-to-bottom for the first empty cell (value `0`)
2. Try placing digits `1–9` in that cell
3. For each digit, validate it against three constraints:
   - Not already in the same **row**
   - Not already in the same **column**
   - Not already in the same **3×3 sub-grid**
4. If valid, place the digit and recurse into the next empty cell
5. If no digit works, **backtrack** — reset the cell to `0` and try the next option in the previous cell
6. Repeat until the grid is fully filled or all options are exhausted

---

## 📐 Constraints Checked (`isValid`)

```
Row check    → grid[row][0..8]
Column check → grid[0..8][col]
Box check    → grid[startRow..startRow+2][startCol..startCol+2]
               where startRow = 3 * (row / 3)
                     startCol = 3 * (col / 3)
```

---

## 📁 Project Structure

```
sudoku-solver/
└── sudoku.cpp      # All logic in a single file
```

### Key Functions

| Function | Description |
|---|---|
| `isValid(grid, row, col, num)` | Checks if placing `num` at `(row, col)` is legal |
| `solveSudoku(grid)` | Recursively solves the puzzle via backtracking |
| `printGrid(grid)` | Prints the 9×9 grid to stdout |

---

## 🔧 Using a Custom Puzzle

Edit the `grid` in `main()` — use `0` for empty cells:

```cpp
vector<vector<int>> grid = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    // ... 7 more rows
};
```

The grid must be a valid 9×9 Sudoku layout. Puzzles with no solution will print:

```
No solution exists.
```

---

## ⏱️ Complexity

| | Complexity |
|---|---|
| **Time (worst case)** | O(9^m) where m = number of empty cells |
| **Space** | O(m) recursion stack depth |

In practice, constraint checking prunes the search tree heavily, making most real-world puzzles solve near-instantly.

---

## 🛠️ Requirements

- C++11 or later
- Any standard compiler: `g++`, `clang++`, MSVC

---

## 📄 License

MIT — free to use and modify.
