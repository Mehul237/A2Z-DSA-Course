
[Minimum Cost of ropes - Queue, Heap](https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1)


![Heap 2-11](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/2c9aebc8-f636-4bfb-bcb5-0e2f80e4c389)
![Heap 2-12](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/f89d8e27-5060-478d-893f-81c38b24c241)

```cpp
class Solution {
    public:
    
    long long minCost(long long arr[], long long n) {
        
        // Min cost: Sorted ropes length take first (min-heap)
        priority_queue<long long, vector<long long>, greater<long long>>pq;
        
        // Step-01: Push element into min-heap
        for(int i=0; i<n; i++) {
            pq.push(arr[i]);
        }
        
        // Step-02: Take 2 element and add ropesCost
        long long ropesCost = 0;
        
        while(pq.size() > 1) {
            
            long long a = pq.top();
            pq.pop();
            
            long long b = pq.top();
            pq.pop();
            
            long long sum = a + b;
            ropesCost += sum;
            
            // 2 element sum push into pq
            pq.push(sum);
        }
        return ropesCost;
    }
};

// TC: O(N logN)
// SC: O(N)
```
