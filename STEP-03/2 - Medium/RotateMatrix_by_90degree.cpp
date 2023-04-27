
/*
-----------------------------------------------------------------------------------------------------------------------------------
Problem Statement: Given a matrix, your task is to rotate the matrix 90 degrees clockwise.                                        +
                                                                                                                                  +
Brute force Method                                                                                                                +
Approach:                                                                                                                         +
 - Take another dummy matrix of n*n, and then take the first row of the matrix and put it in the last column of the dummy matrix, + 
 - take the second row of the matrix, and put it in the second last column of the matrix and so.                                  +
                                                                                                                                  +
 Time Complexity: O(N*N) to linearly iterate and put it into some other matrix.                                                   +
                                                                                                                                  +
Space Complexity: O(N*N) to copy it into some other matrix.                                                                       +
 -----------------------------------------------------------------------------------------------------------------------------------
*/

vector < vector < int >> rotate(vector < vector < int >> & matrix) {
  int n = matrix.size();
  vector < vector < int >> rotated(n, vector < int > (n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      rotated[j][n - i - 1] = matrix[i][j];
    }
  }
  return rotated;
}



/*
----------------------------------------------------------------------------------------------------------------------------------------------------------------
Optimized approach                                                                                                                                             +
                                                                                                                                                               +
Intuition:                                                                                                                                                     +
- By observation, we see that the first column of the original matrix is the reverse of the first row of the rotated matrix,                                   +
 so that’s why we transpose the matrix and then reverse each row, and since we are making changes in the matrix itself space complexity gets reduced to O(1).  +
                                                                                                                                                               +
Approach:                                                                                                                                                      +
  - Transpose the matrix. (transposing means changing columns to rows and rows to columns)                                                                     +
  - Reverse each row of the matrix.                                                                                                                            + 
                                                                                                                                                               +  
Time Complexity: O(N*N) + O(N*N).                                                                                                                              +
 - One O(N*N) is for transposing the matrix and the other is for reversing the matrix.                                                                         +
                                                                                                                                                               +
Space Complexity: O(1)                                                                                                                                         +
----------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

void rotate(vector < vector < int >> & matrix) {
  int n = matrix.size();
  
  //transposing the matrix
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }
  
  //reversing each row of the matrix
  for (int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
  }
}
