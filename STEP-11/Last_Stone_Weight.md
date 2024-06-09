

<hr>

![Screenshot 2024-06-09 232450](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/893e7f35-b209-435e-b193-c4ab79f948f8)

<hr>
<br>

### Dry-run

![Screenshot 2024-06-09 232353](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/e8fd2260-69c7-4e75-a5a8-d307de8455df)

![Screenshot 2024-06-09 232632](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/f600a301-8a01-48fd-8491-3edecd8bfd46)

<hr>
<br>

### Approach:

![Screenshot 2024-06-09 231402](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/0493d392-f38f-4803-8160-bd52d56d004e)

![Screenshot 2024-06-09 232910](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/c1cd0068-5d20-4f21-aa78-c4f59a2e6e17)

![Screenshot 2024-06-09 232950](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/0e23101d-abf3-4e27-97f4-3cb94b5c06b6)

<hr>
<br>

- Take two heavy stone first
- According to that have 3 condition,
- 1. If X == Y then both are destroyed
  2. If X > Y, Then Y destroyed and X new weight X - Y
  3. If X < Y, Then X destroyed and Y new weight Y - X
- Return left stone one value, If not then 0

<hr>

```cpp

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq; //max heap

        for(int i=0; i<stones.size(); i++) {
            pq.push(stones[i]);
        }

        // Simulate smashing stones
        while (pq.size() > 1) {

            int x = pq.top(); pq.pop();    // Take the heaviest stone
            int y = pq.top(); pq.pop();    // Take the second heaviest stone
            if (x > y) pq.push(x - y);     // If X is heavier than Y, smash Y and update X's weight

            // Comment: If X == Y, then both stones are destroyed, so no action is taken
            // Comment: If X < Y, then X is destroyed and Y's weight is updated, so no action is taken
        }

        // Return the weight of the last remaining stone, if any
        return pq.empty() ? 0 : pq.top();
    }
};

// TC: O(N logN)
// SC: O(N)
```

<hr>
