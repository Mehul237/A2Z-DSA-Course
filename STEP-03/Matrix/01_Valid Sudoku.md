
## Problem Statement

![Screenshot 2024-06-25 164948](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/ac19caaa-5abe-449b-ba6a-7b5104c619cf)

## 1. Brute-force approach: Recursion

### Approach
<hr>

- Try every possible number from 1 to 9 and check in row, col and grid 3*3
- Solve only 1 grid and rest of sudoku solve by recursion
   - Pattern where solving a smaller version of the problem contributes to solving the larger problem are good candidates for recursion

### Steps for implementation
<hr>

- Step-01: Generate all boards
- Step-02: Validate all boards
- Step-03: Return valid board

```cpp

class Solution {
public:

    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        // Check current row and column
        for (int i = 0; i < 9; ++i) {
            if (i != col && board[row][i] == num) {
                return false;
            }
            if (i != row && board[i][col] == num) {
                return false;
            }
        }
        
        // Check 3x3 sub-grid
        int startRow = 3 * (row / 3);
        int startCol = 3 * (col / 3);
        for (int i = startRow; i < startRow + 3; ++i) {
            for (int j = startCol; j < startCol + 3; ++j) {
                if (i != row && j != col && board[i][j] == num) {
                    return false;
                }
            }
        }
        return true;
    }


    bool isValidSudokuRecursive(vector<vector<char>>& board, int row, int col) {

        // Base case: If we've reached beyond the last row, the board is valid
        if (row == 9) {
            return true;
        }
        
        // Move to the next row if we've reached the end of the current row
        if (col == 9) {
            return isValidSudokuRecursive(board, row + 1, 0);
        }
        
        // If current cell is not empty, validate it
        if (board[row][col] != '.') {
            if (!isValid(board, row, col, board[row][col])) {
                return false;
            }
        }
        
        // Move to the next column
        return isValidSudokuRecursive(board, row, col + 1);
    }


    bool isValidSudoku(vector<vector<char>>& board) {
        return isValidSudokuRecursive(board, 0, 0);
    }
};

```

<br>

### 2. Optimal solution: Backtracking
<hr>

- [Article](https://takeuforward.org/data-structure/sudoku-solver/)

![Screenshot 2024-06-25 165452](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/5143f520-5c9a-4f48-96de-9f8517cdfe23)


```cpp

bool isValid(vector < vector < char >> & board, int row, int col, char c) {
  for (int i = 0; i < 9; i++) {
    if (board[i][col] == c)
      return false;

    if (board[row][i] == c)
      return false;

    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
      return false;
  }
  return true;
}

bool solveSudoku(vector < vector < char >> & board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      if (board[i][j] == '.') {
        for (char c = '1'; c <= '9'; c++) {
          if (isValid(board, i, j, c)) {
            board[i][j] = c;

            if (solveSudoku(board))
              return true;
            else
              board[i][j] = '.';
          }
        }

        return false;
      }
    }
  }
  return true;
}

// TC: 9*m, m = no. of empty cells
// SC: O(1), because only 81 recursion call made in recursive call stack, so it is constant

```


<br>

### 3. Using only loops

```cpp

class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int cur_row, int cur_col, char value) {

        for (int i = 0; i < 9; i++) {

            // 1. row check
            if (board[i][cur_col] == value && i != cur_row) {
                return false;
            }

            // 2. column check
            if (board[cur_row][i] == value && i != cur_col) {
                return false;
            }

            // 3. 3x3 matrix check
            int nr = 3 * (cur_row / 3) + (i / 3);
            int nc = 3 * (cur_col / 3) + (i % 3);
            if (board[nr][nc] == value && nr != cur_row && nc != cur_col) {
                return false;
            }
        }
        return true;
    }


    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (isSafe(board, i, j, board[i][j]) == false) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
```


<br>

```cpp


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

  bool isSafe(char value, vector<vector<char>>& board, int curr_row, int curr_col) {
    // 1. Row check
    for (int col = 0; col < 9; col++) {
      if (board[curr_row][col] == value) {
        return false;
      }
    }

    // 2. Column check
    for (int row = 0; row < 9; row++) {
      if (board[row][curr_col] == value) {
        return false;
      }
    }

    // 3. 3*3 matrix check
    int startRow = 3 * (curr_row / 3);
    int startCol = 3 * (curr_col / 3);
    
    for (int i=startRow; i<startRow + 3; i++) {
      for (int j=startCol; j<startCol + 3; j++) {
        if (board[i][j] == value) {
          return false;
        }
      }
    }
    return true;
  }


  bool solve(vector<vector<char>>& board) {
    int n = board.size();

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {

        // Case-01: Check empty cell
        if (board[i][j] == '.') {
          
          // Try value from 1 to 9 to place into board
          for (char value = '1'; value <= '9'; value++) {
            
            // Check for safety
            if (isSafe(value, board, i, j)) {
              
              // Insert value
              board[i][j] = value;
              
              // Recursively solve
              if (solve(board)) {
                return true;
              }
             
              // Backtrack
              board[i][j] = '.';
            }
          }
          return false;
        }
      }
    }
    return true;
  }


  void solveSudoku(vector<vector<char>>& board) {
    solve(board);
    printBoard(board);
  }


  void printBoard(vector<vector<char>>& board) {
    int n = board.size();
    
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << board[i][j] << " ";
        
        if ((j + 1) % 3 == 0 && j != n - 1) {
          cout << "| ";
        }
    }
    
    cout << endl;
    if ((i + 1) % 3 == 0 && i != n - 1) {
      cout << "------+-------+------" << endl;
    }
  }
}

};



int main() {
  vector<vector<char>> board = {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  Solution solver;
  solver.solveSudoku(board);

  return 0;
}


```
