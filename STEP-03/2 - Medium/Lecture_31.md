```cpp

#include <bits/stdc++.h>
using namespace std;



void addTwo(int arr1[][3], int arr2[][3]) {

  int temp[3][3];

  for(int i=0; i<3; i++) {
    for(int j=0; j<3; j++) {
      temp[i][j] = arr1[i][j] + arr2[i][j];
    }
  }

  for(int i=0; i<3; i++) {
    for(int j=0; j<3; j++) {
      cout << temp[i][j] << " ";
    }
    cout << "\n";
  }
}



void sumOfDiagonal(vector<vector<int>> &mat) {

  int nRow = mat.size();
  int mCol = mat[0].size();

  int first = 0;

  for(int i=0; i<3; i++) {
    first += mat[i][i];
  }

  int sec = 0;
  int i=0, j=mCol-1;

  while(j>=0) {
    sec += mat[i][j];
    i++, j--;
  }
  cout << first << " " << sec;
}



void reverseMatrix(vector<vector<int>> &mat) {

  int nRow = mat.size();
  int mCol = mat[0].size();

  for(int i=0; i<nRow; i++) {

    int start = 0;
    int end = mCol-1;

    while(start < end) {
      swap(mat[i][start++], mat[i][end--]);
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


// 1. Add two Matrix 
  int arr1[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int arr2[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  cout << " -- Addition of Two matrix -- " << "\n";
  addTwo(arr1, arr2);
  cout << "\n";


// 2. Print sum of diagonal element
  vector<vector<int>> mat1   { {1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16} };
  
  cout << "Sum of Diagonal, First and Sec: " << "\n";
  sumOfDiagonal(mat1);
  cout << "\n";
  cout << "\n";


// 3. Reverse each row of matrix
  cout << "-- Reverse matrix --" << "\n"; 
  reverseMatrix(mat1);


  return 0;
}

```
