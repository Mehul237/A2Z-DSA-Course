
  **Difficulty**: Medium  <br>
  **Topics**: Array, 2 Pointer  <br>
  **Description**: The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

**Example**:  
Input: 123   <br>
Output: 132   

<br>
<hr>

![Screenshot 2024-10-15 231915](https://github.com/user-attachments/assets/bccd174b-ddaf-4e9e-9edf-0b30564da306)

<hr>
<br>

![Screenshot 2024-10-18 044430](https://github.com/user-attachments/assets/e7b5b182-ebda-473b-9946-58fa5b24848c)


```cpp
// TC: O(N)
// SC: O(1)

class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    const int n = nums.size();

    // From back to front, find the first number < nums[i + 1].
    int i;
    for (i = n - 2; i >= 0; --i)
      if (nums[i] < nums[i + 1])
        break;

    // From back to front, find the first number > nums[i], swap it with
    // nums[i].
    if (i >= 0)
      for (int j = n - 1; j > i; --j)
        if (nums[j] > nums[i]) {
          swap(nums[i], nums[j]);
          break;
        }

    // Reverse nums[i + 1..n - 1].
    reverse(nums, i + 1, n - 1);
  }

 private:
  void reverse(vector<int>& nums, int l, int r) {
    while (l < r)
      swap(nums[l++], nums[r--]);
  }
};

```
