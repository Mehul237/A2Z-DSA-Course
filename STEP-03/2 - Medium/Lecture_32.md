
```cpp
#include <bits/stdc++.h>
using namespace std;

void wave(vector<vector<int>> mat, int row, int Mcol) {
  
  int nRow = mat.size();
  int mCol = mat[0].size();

  for(int col=0; col<Mcol; col++) {
    
    // Case-01: Odd --> Bottom to Top
    if(col & 1) {
      for(int row=nRow-1; row>=0; row--) {
        cout << mat[row][col] << " ";
      }
      cout << "\n";
    }

    // Case-02: Even --> Top to Bottom
    else {
       for(int row=0; row<nRow; row++) {
        cout << mat[row][col] << " ";
      }
    }
  }
}


vector<int> printSpiral(vector<vector<int>> mat) {

  int nRow = mat.size();
  int mCol = mat[0].size();
  vector<int>ans;
  
  // 01. ColBegin to ColEnd
  int left = 0;
  int right = mCol - 1;

  // 02. RowBeing to RowEnd
  int top = 0;
  int bottom = nRow - 1;

  while(top <= bottom && left <= right) {

    // Print top: Left to right
    for(int j = left; j<=right; j++) {
      ans.push_back(mat[top][j]);
    }
    top++;

    // Print Right: Top to bottom
    for(int i=top; i<=bottom; i++) {
      ans.push_back(mat[i][right]);
    }
    right--;

    // Print Bottom: Right to left
    if (top <= bottom) {
      for(int j=right; j>=left; j--) {
        ans.push_back(mat[bottom][j]);
      }
      bottom--;
    }

    // Print left: Bottom to Top
    if(left <= right) {
      for(int i=bottom; i>=top; i--) {
        ans.push_back(mat[i][left]);
      }
      left++;
    }
  }
  return ans;
}



void transposeMatrix(vector<vector<int>> &mat) {

  int nRow = mat.size();
  int mCol = mat[0].size();

  for(int i=0; i<=nRow-1; i++) {
    for(int j=i+1; j<nRow; j++) {
      swap(mat[i][j], mat[j][i]);
    }
  }

  for(int i=0; i<nRow; i++) {
    for(int j=0; j<mCol; j++) {
      cout << mat[i][j] << " ";
    }
    cout << "\n";
  }

}


int main() {
    
/*

  -----------------
  2D Vector create
  ----------------

  1 method: vector < vector<int> > matrix;

  2 method: vector < vector<int> > matrix (row, vector<int> (col, initilising))
                                            3                 4,   2
*/



// 1. Manual print
  vector< vector<int> > matrix1(3, vector<int>(4, 1));

  for(int i=0; i<3; i++) {
    for(int j=0; j<4; j++) {
      cout << matrix1[i][j] << " ";
    }
    cout << "\n";
  }



// 2. Taking input from user
  int row, col;
  cout << "Enter row and col: ";
  cin >> row >> col;

  vector< vector<int> > mat(row, vector<int>(col));
  int rowSize = mat.size();
  int colSize = mat[0].size();

  for(int i=0; i<rowSize; i++) {
    for(int j=0; j<colSize; j++) {
      cin >> mat[i][j];
    }
  }

  for(int i=0; i<rowSize; i++) {
    for(int j=0; j<colSize; j++) {
      cout << mat[i][j]  << " ";
    }
    cout << "\n";
  }



// 3. Wave form
  vector<vector<int>>matrix = { {1, 2}, {3, 4} };
  wave(matrix, 2, 2);



// 4. Spiral print  - - Nishant, Codehelp, Coder army
  vector<vector<int>> mat1   { {1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16} };
		                     
  vector<int> ans = printSpiral(mat1);

  for(int i=0; i<ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << "\n"; 

// 5. Transpose Matrix
  transposeMatrix(mat1);
 

  return 0;
}

```
