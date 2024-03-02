
## Rotate matrix by k times

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

  // Rotate matrix by 90 degrees clockwise
  vector<vector<int>> arr = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };
    
  int k;
  cin >> k;

  k %= 4;
    
 while(k) {
  
  rotate(arr);
   k--;
  }

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
