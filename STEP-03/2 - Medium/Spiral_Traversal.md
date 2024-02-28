# Optimal Approach

In this approach, we will be using four loops to print all four sides of the matrix.

- **1st loop:** This will print the elements from left to right
- **2nd loop:**  -------------------------------- top to bottom
- **3rd loop:**  -------------------------------- right to left
- **4th loop:**  -------------------------------- bottom to top

## Steps:

1. Create and initialize variables:
   - `top` as the starting row index
   - `bottom` as the ending row index
   - `left` as the starting column index
   - `right` as the ending column index.
   
2. In each outer loop traversal, print the elements of a square in a clockwise manner.
3. Print the top row:
   - Print the elements of the top row from column index `left` to `right` and increase the count of `top` to move to the next row.
4. Print the right column:
   - Print the rightmost column from row index `top` to `bottom` and decrease the count of `right`.
5. Print the bottom row:
   - If `top <= bottom`, then print the elements of the bottom row from column `right` to `left` and decrease the count of `bottom`.
6. Print the left column:
   - If `left <= right`, then print the elements of the left column from the bottom row to the top row and increase the count of `left`.
7. Run a loop until all the squares of loops are printed.


## Note: 
 - As we can see in the code snippet below, 'two edge conditions' are being added in the last two ‘for’ loops: when we are moving from right to left and from bottom to top. 


## Conditions:
- These conditions are added to check if the matrix is a single column or a single row.
- When a single row is present, it cannot be traversed again backward, so the condition is checked in the right-to-left loop.
- When a single column is present, elements from bottom to top cannot be traversed again, so the condition is checked in the bottom-to-top loop.


## Implementation - 01                                                                                                

```cpp

class Solution {   
    public: 
    
    /*
------------------------------------------------
    Note:
    1. Find no. of rows
       --> int row = matrix.size();
    2. Find no. of column
       --> int column = matrix[0].size();
------------------------------------------------
    */
    
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        
    // Initialize the pointers req for traversal
    
        // For column begin to colEnd -- Left to right
        int left = 0;
        int right = c-1;
        
        // For rowBegin to rowEnd -- Top to bottom
        int top = 0;
        int bottom = r-1;
        
        vector<int> ans;
        
        // Loop until all elements are not traversed
        while(top <= bottom && left <= right) {
            
            // Step-01: For moving left to right
            for(int i=left; i<=right; i++) {
                ans.push_back(matrix[top][i]);
            }
            
            // Step-02: For moving Top to bottom
            top++;
            
            for(int i=top; i<=bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            
            // Step-03: For moving Right to left
            right--;
            
            if(top <= bottom) {
                for(int i=right; i>=left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            // Step-04: For moving Bottom to top
            if(left <= right) {
                for(int i=bottom; i>=top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};

```

## Implementation - 02

```cpp

#include <bits/stdc++.h>
using namespace std;

vector<int> printSpiral(vector<vector<int>> mat) {
 
  // Define ans array to store the result.
  vector<int> ans;
 
  int n = mat.size(); // no. of nows
  int m = mat[0].size(); // no. of columns
  
  // Initialize the pointers reqd for traversal.
  int top = 0, left = 0, bottom = n - 1, right = m - 1;

  // Loop until all elements are not traversed.
  while (top <= bottom && left <= right) {
      
    // For moving left to right
    for (int i = left; i <= right; i++)
      ans.push_back(mat[top][i]);

    top++;

    // For moving top to bottom.
    for (int i = top; i <= bottom; i++)
      ans.push_back(mat[i][right]);

    right--;
    
    // For moving right to left.
    if (top <= bottom) {
      for (int i = right; i >= left; i--)
       ans.push_back(mat[bottom][i]);

      bottom--;
    }

    // For moving bottom to top.
    if (left <= right) {
      for (int i = bottom; i >= top; i--)
        ans.push_back(mat[i][left]);

      left++;
    }
  }
  return ans;
}


int main() {
    
  //Matrix initialization.
  vector<vector<int>> mat   { {1, 2, 3, 4},
                              {5, 6, 7, 8},
                              {9, 10, 11, 12},
                              {13, 14, 15, 16} };
		                     
  vector<int> ans = printSpiral(mat);

  for(int i=0;i <ans.size(); i++) {
      cout << ans[i] << " ";
  }
  cout << '\n;
  
  return 0;
}

```


## Time Complexity: O(m x n)
- Since all the elements are being traversed once and there are total `n x m` elements (m elements in each row and total n rows), the time complexity will be O(n x m).

## Space Complexity: O(n)
- Extra space used for storing traversal in the `ans` array
