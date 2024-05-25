
Tag: Array, DP
<hr>

[121. Best Time to Buy and Sell Stock - Variation 1](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)

![Variation 1 | Dry run](https://drive.google.com/uc?id=1JimBEqShi_S_Uo5W1JoBi-G-IKbR2uVd)
![Dry run 02](https://drive.google.com/uc?id=1LzCrHS7e9JeGr4ggZw_WAvyMUddwSBgM)
![Dry run 03](https://drive.google.com/uc?id=1CAVt5vE9o9pEyP7LbHZ3kWAZPfB_EMF1)


```cpp
// Case --> 7, 1, 5, 3, 6, 4

// TC: O(N)
// SC: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0;

        for(int i=1; i<prices.size(); i++) {
            int diff = prices[i] - mini;
            profit = max(profit, diff);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};
```
