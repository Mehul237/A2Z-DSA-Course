
```cpp

#include <bits/stdc++.h>
using namespace std;


int singleNumber(vector<int>& nums) {
    int xorAns = 0;

    for (int i = 0; i < nums.size(); i++) {
        xorAns ^= nums[i];
    }
    return xorAns;
}


int singleNumber1(vector<int>& nums) {
    int xorAns = 0;

    for (auto it : nums) {
        xorAns ^= it;
    }
    return xorAns;
}


int main() {

    vector<int> nums = {4, 1, 2, 1, 2};
    cout << singleNumber(nums);

    return 0;
}
```

</pre>

<pre><strong>Time Complexity: </strong> O(n)
 - The function iterates through each element in the input vector once, performing constant-time operations
 - Therefore, the time complexity of the function is O(n), where n is the number of elements in the input vector
  
<strong>Space Complexity:</strong> O(1)
 - The function only uses a constant amount of extra space regardless of the input size
 - It stores only a single variable xorAns
 - Therefore, the space complexity of the function is O(1)
  
</pre>
