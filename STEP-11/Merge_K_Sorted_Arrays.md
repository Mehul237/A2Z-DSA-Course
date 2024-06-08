
[Merge K sorted arrays](https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1)


```cpp

class Solution {
public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {

        // 1. Create a min-heap to efficiently store the smallest elements
        priority_queue<int, vector<int>, greater<int>> pq;

        // 2. Push all elements from the K sorted arrays into the min-heap
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < K; j++) {
                pq.push(arr[i][j]);
            }
        }

        vector<int> ans;

        // 4. Iteratively extract the smallest element and add it to the result
        while (!pq.empty()) {

            // Extract the element with the highest priority (smallest value) from the min-heap
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};

// sort will take O(k*k*logk*k)
// TC:  k*k log k
// SC:  k*k (k^2

```
