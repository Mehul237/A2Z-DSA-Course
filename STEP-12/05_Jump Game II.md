
## Variation-2: Tell me the minimum jumps that you will take to reach the end

<br>

<hr>

![Screenshot 2024-06-27 234333](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/9368c257-fc7e-4896-bba0-3c6b68950dd4)

<hr>
<br>

```cpp

class Solution {
public:
    int jump(vector<int>& nums) {
        int near = 0;   // left
        int far = 0;    // right
        int jumps = 0;

        while (far < nums.size() - 1) {
            int farthest = 0;
            for (int i = near; i <= far; i++) {
                farthest = max(farthest, i + nums[i]);
            }
            near = far + 1;
            far = farthest;
            jumps++;
        }
        return jumps;        
    }
};

// TC: O(N)
// SC: O(1)

// https://leetcode.com/problems/jump-game-ii/solutions/5292559/video-keep-near-and-far-position-and-get-the-farthest-position

```
