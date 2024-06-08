
## Q1: Kth Smallest element

![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20221220165711/MinHeapAndMaxHeap1.png)

[How to implement Max and min heap using STL (PQ)?](https://www.geeksforgeeks.org/implement-min-heap-using-stl/)

<hr>

```cpp

class Solution {
    public:
    
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this fn
    
    // Smallest: max-heap
    // Largest: min-heap
    
    int kthSmallest(int arr[], int l, int r, int k) {
        
        priority_queue<int> pq;
        
        // Step-01: 1st push k element into pq
        for(int i=0; i<k; i++) {        // O(k * logK)
            pq.push(arr[i]);
        }
        
        // Step-02: For rest element (k, n-1)th element
        for(int i=k; i<=r; i++) {
            if(arr[i] < pq.top()) {    // O( (n-k) * log k)
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        // Step-03: ans = pq.top()
        return pq.top();
    }
};


// TC: O(N logK)
// SC: O(K)

```

<hr>

```cpp

class Solution {
    public:

    int kthSmallest(int arr[], int l, int r, int k) {
  
        priority_queue <int> maxHeap;
        for(int i = l; i <= r; i++) {
            maxHeap.push(arr[i]);
            if(maxHeap.size() > k) {
                maxHeap.pop();
            }
          
        }
        return maxHeap.top();
    }  
};

// TC: O(logK)
// SC: O(K)
```

<hr>


Follow up: [Kth largest element](https://leetcode.com/problems/kth-largest-element-in-an-array/)

```cpp

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // min-heap prioritizes the smallest element at the top
        priority_queue<int, vector<int>, greater<int>> pq;  

        // Step-01: 1st push k element into pq
        for (int i=0; i<k; i++) { // O(k * logK)
            pq.push(nums[i]);
        }

        // Step-02: For rest element (k, n-1)th element
        for (int i = k; i <nums.size(); i++) {
            if (nums[i] > pq.top()) { // O( (n-k) * log k)
                pq.pop();
                pq.push(nums[i]);
            }
        }

        // Step-03: ans = pq.top()
        return pq.top();
    }
};


// TC: O(N logK)
// SC: O(K)
```

<hr>
