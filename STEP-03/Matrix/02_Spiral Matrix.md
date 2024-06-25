<hr>

![DocScanner 25 Jun 2024 11-38 pm_1](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/c7ab34fa-e5d6-415d-87d6-2c4680e27d54)

![DocScanner 25 Jun 2024 11-38 pm_2](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/b2292e4b-7574-4e0b-b543-a095a72fd361)

<hr>
<br>

```cpp

#include <bits/stdc++.h>
using namespace std;

vector<int> printSpiral(vector<vector<int>>mat) {
  int r = mat.size();
  int c = mat[0].size();

  vector<int> ans;

  // Left to right (row): Column (Opposite)
  int left = 0;
  int right = c-1;

  // Top to bottom (column): Row (Opposite)
  int top = 0;
  int bottom = r-1;

  while(top <= bottom && left <= right) {

    // 1. Left to Right
    for(int i=left; i<=right; i++) {
      ans.push_back(mat[top][i]);
    }
    top++;

    // 2. Top to Bottom
    for(int i=top; i<=bottom; i++) {
      ans.push_back(mat[i][right]);
    }
    right--;

    // 3. Right to Left
    if(top <= bottom) {
      for(int i=right; i>=left; i--) {
        ans.push_back(mat[bottom][i]);
      }
      bottom--;
    }

    // 4. Bottom to Top
    if(left <= right) {
      for(int i=bottom; i>=top; i--) {
        ans.push_back(mat[i][left]);
      }
      left++;
    }
  }
  return ans;
}



int main() {

  vector<vector<int>> mat { {1, 2, 3, 4},
                            {5, 6, 7, 8},
                            {9, 10, 11, 12},
                            {13, 14, 15, 16}  };
  
  vector<int>ans = printSpiral(mat);
  for(int i=0; i<ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";


  return 0;
}


// TC: O(N*M), Since traverse all elements once
// SC: O(N), Storing traversed ans array
```
