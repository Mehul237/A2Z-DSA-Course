# Fractional Knapsack

## Problem Description

Given weights and values of `N` items, we need to put these items in a knapsack of capacity `W` to get the maximum total value in the knapsack. Unlike 0/1 knapsack, you are allowed to break the item.

### Example 1:
**Input:**
- `N = 3, W = 50`
- `values[] = {60, 100, 120}`
- `weights[] = {10, 20, 30}`

**Output:**
- `240.00`

**Explanation:**
Total maximum value of items we can have is 240.00 from the given capacity of sack.

### Example 2:
**Input:**
- `N = 2, W = 50`
- `values[] = {60, 100}`
- `weights[] = {10, 20}`

**Output:**
- `160.00`

**Explanation:**
Total maximum value of items we can have is 160.00 from the given capacity of sack.

### Constraints:
- `1 <= N <= 10^5`
- `1 <= W <= 10^9`
- `1 <= valuei, weighti <= 10^4`

---

<br>


## Your Task
Complete the function `fractionalKnapsack()` that receives maximum capacity `W`, an array of items (`Items`), and size `n`. It returns a double value representing the maximum value in the knapsack.

## Solution Explanation

To solve the Fractional Knapsack problem efficiently, we use a greedy algorithm. Here's a step-by-step explanation of the approach:

1. **Calculate value per unit weight**: Compute the value-to-weight ratio for each item.
   \[
   \text{value per unit weight} = \frac{\text{value of item}}{\text{weight of item}}
   \]

2. **Sort items**: Sort all items based on their value-to-weight ratio in descending order. This allows us to pick the most valuable items first.

3. **Fill the knapsack**: Iterate through the sorted list of items and add items to the knapsack until either the knapsack is full or there are no more items left.
   - If adding the next whole item exceeds the remaining capacity of the knapsack, take a fraction of it to fill the knapsack exactly to its capacity.

4. **Compute total value**: Sum up the values of the items included in the knapsack.


<hr>
<br>

```cpp


// class implemented

/*
struct Item {
    int value;
    int weight;
};
*/

class Solution {
public:
    bool static cmp(struct Item a, struct Item b) {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }

    double fractionalKnapsack(int W, Item arr[], int n) {

        // Step-01: Sort items by their value/weight ratio in descending order
        sort(arr, arr + n, cmp);

        int curWeight = 0;
        double finalvalue = 0.0;

        // Step0-02: Fill the Knapsack
        for (int i = 0; i < n; i++) {

            // Case-01: If adding the whole item is within capacity, add it completely
            if (curWeight + arr[i].weight <= W) {
                curWeight += arr[i].weight;
                finalvalue += arr[i].value;
            }

            // Case-02: If not then, Calculate per unit weight
            // -- remainingWT_Value = (Value / wt) * remainingWT
            // -- If not, take a fraction of the item to fill the knapsack exactly to its capacity
            else {
                int remainingWT_Value = W - curWeight;
                finalvalue += (arr[i].value / (double)arr[i].weight) * (double)remainingWT_Value;
                break;
            }
        }
        return finalvalue;
    }
};

// TC: O(N + N logN), Iterate through all the items and sort the items to find the answer
// SC: O(1)

```


