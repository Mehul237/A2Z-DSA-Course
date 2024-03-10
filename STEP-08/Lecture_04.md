
```cpp

#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> subsets(vector<int> &nums) {

    vector <vector<int>> ans;
    int n = nums.size();
    int subset = 1 << n;                           // pow(2, n)

    for (int num=0; num<subset; num++) {
        vector<int> list;
        for (int i=0; i<n; i++) {
            if (num & (1 << i)) {                // 1. Check if the i-th bit is set or not
                list.push_back(nums[i]);
            }
        }
        ans.push_back(list);
    }
    return ans;
}


void printSubsets(const vector<vector<int>>& subsets) {
    for (auto subset : subsets) {
        cout << "[";
        for (int num : subset) {
            cout << num;
        }
        cout << "], ";
    }
}


int main() {

    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);

    printSubsets(result);
    return 0;
}
```

</pre>

<pre><strong>Time Complexity: </strong> O(n * 2^n)
 - Generating all subsets involves iterating through all possible combinations of elements in the input vector
 - There are 2^n subsets for a vector of size n, where n is the number of elements in the input vector
 - For each subset, 
   We iterate through the elements of the input vector once to determine which elements to include in the subset
 - Therefore, the time complexity of generating all subsets is O(n * 2^n)
  
<strong>Space Complexity:</strong> O(n * 2^n)
- The space complexity is determined by the space required to store all generated subsets
- Since there can be 2^n subsets, the space complexity for storing all subsets is O(2^n)
- Additionally, there is auxiliary space used for storing temporary vectors during the subset generation process
  However, this additional space is negligible compared to the space required for storing all subsets
- Overall, the dominant factor in space complexity is the number of subsets, which is O(2^n)
  
</pre>
