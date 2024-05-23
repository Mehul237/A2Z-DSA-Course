
[Intuition](https://docs.google.com/document/d/18KlOkADNvGreQzdkWOjn7aXzPXCS8QcLoThhDpLqzV4/edit?usp=sharing)

```cpp

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        // Sort the greed factors and cookie sizes
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        // Initialize pointers and count
        int i = 0, j = 0, count = 0;

        // Iterate through both arrays
        while (i < g.size() && j < s.size()) {

            // If the current cookie is large enough, satisfy the child
            if (s[j] >= g[i]) {
                count++;
                i++;
            }
            
            // Move to the next cookie, regardless of whether it satisfies the current child
            j++;
        }
        return count;
    }
};

```


```cpp
// Striver: Greedy algo
// TC: )(N logN + M logM + M)  ~= O(N logN)
// SC: 0(1)

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        // Left = Cookies (M),   right = Greed factor (N)
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        int left = 0, right = 0;

        // while (left < s.size() && right < g.size()) {
        //     if (g[right] <= s[left]) {
        //         right++;
        //     }
        //     left++;
        // }
        // return right;

        while (left < s.size() && right < g.size()) {
            if (s[left] >= g[right]) {
                left++;
            }
            right++;
        }
        return left;
    }
};

```
