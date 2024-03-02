## Problem Statement: 
> Given a matrix, your task is to rotate the matrix 90 degrees clockwise

<br>

## Brute force Approach / Intuition:                                                                                                                         
>  - Take another dummy matrix of n*n, and then take the first row of the matrix and put it in the last column of the dummy matrix,  
>  - take the second row of the matrix, and put it in the second last column of the matrix and so.                                  

 ### Brute force approach Implementation,
                                                                      
```cpp

#include<bits/stdc++.h>
using namespace std;

vector<vector<int >>  rotate(vector <vector< int>> & mat) {

  // m*n (row*col)
  int mRow = mat.size();
  int nCol = mat[0].size();
    
  // created new rotated vector to stored the ans   
  vector<vector<int>> rotated(mRow, vector<int> (nCol, 0));
  for (int row=0; row<mRow; row++) {
    for (int col=0; col<nCol; col++) {
      rotated[col][mRow - 1 - row] = mat[row][col];
    }
  }
  return rotated;
}


int main() {
    

// 01. Rotate matrix by 90 degree clock-wise
  vector<vector<int >> arr;
  arr =  { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };
  
  vector<vector<int>> rotated = rotate(arr);
  cout << "-- Rotated Image --" << "\n";

  for (int i=0; i<rotated.size(); i++) {
    for (int j=0; j<rotated[0].size(); j++) {
      cout << rotated[i][j] << " ";
    }
    cout << "\n";
  }


  return 0;
}


```


<br>

--------------------------------------------------------------------------------------------------------------------
>  <em> **Time Complexity:** O(N*N) </em>
>  - to linearly iterate and put it into some other matrix.
>
>  <em> **Space Complexity:** O(N*N) </em>
>  - to copy it into some other matrix.
--------------------------------------------------------------------------------------------------------------------

<br>

## Optimized approach:                                                                                                                                            
                                                                                                                                                               
### Intuition:                                                                                                                                                     
> - By observation, we see that the first column of the original matrix is the reverse of the first row of the rotated matrix,                                   
>  so that’s why we transpose the matrix and then reverse each row, and since we are making changes in the matrix itself space complexity gets reduced to O(1).  
>                                                                                                                                                               

### Approach:                                                                                                                                                      
>  - Transpose the matrix. (transposing means changing columns to rows and rows to columns)                                                                     
>  - Reverse each row of the matrix.                                                                                                                             


 ### Optimize approach Implementation (Space),
 
 ```cpp
#include<bits/stdc++.h>
using namespace std;


void rotate(vector < vector < int >> & matrix) {

  int n = matrix.size();

  // 1. transposing the matrix
    for (int i=0; i<n-1; i++) {
      for (int j=i+1; j<n; j++) {
        swap(matrix[i][j], matrix[j][i]);
    }
  }

  // 2. reversing each row of the matrix
  for (int i=0; i<n; i++) {

    // In interview, You not allow to use in-built function... 
    // So, Alwways have a knowledge of in-built fn working and implementation skill
    // reverse(matrix[i].begin(), matrix[i].end());

    int start = 0;
    int end = n-1;

    while(start < end) {
      swap(matrix[i][start++], matrix[i][end--]);
    }
  }

}


int main() {
    

// 01. Rotate matrix by 90 degree clock-wise
  vector<vector<int >> arr;
  arr =  { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };
  
  rotate(arr);
  cout << "-- Rotated Image --" << "\n";

  for (int i=0; i<arr.size(); i++) {
    for (int j=0; j<arr[0].size(); j++) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }


  return 0;
}


```

<br>

--------------------------------------------------------------------------------------------------------------------
>  <em> **Time Complexity:** O(N*N) + O(N*N) </em>
>  - One O(N*N) is for transposing the matrix and the other is for reversing the matrix.
>
>  <em> **Space Complexity:** O(1) </em>
--------------------------------------------------------------------------------------------------------------------
