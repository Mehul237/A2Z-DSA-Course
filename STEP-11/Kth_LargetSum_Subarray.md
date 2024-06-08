
[Kth Largest Sum Subarray](https://www.naukri.com/code360/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=0)

<hr>

```cpp

// Brute force approach
// Step-01: Find the subarray sum for all the elements
// Step-02: Sort the 'ans' vector
// Step-03: return  ans.size() - k element

#include <bits/stdc++.h>

int getKthLargest(vector<int> &arr, int k) {
    vector<int> sumStore;

	for(int i=0; i<arr.size(); i++) {         // O(N^2)
		int sum = 0;
		for(int j=i; j<arr.size(); j++) {
			sum += arr[j];
			sumStore.push_back(sum);
		}
	}

	sort(sumStore.begin(), sumStore.end());   // O(N^2 logN)
	return sumStore[sumStore.size() - k];
}

// TC: O(N^2 * logN)
// SC: O(N^2)
```

<hr>

```cpp
// Better approach: Min-heap based

// Subarray sum find,
// 1. Using the 2 loops and vector 'ans' to store the subarray sum take TC: O(N^2)
// 2. Using the prefix vector to store the subarray sum take TC: O(N)

#include <bits/stdc++.h>

int getKthLargest(vector<int>& arr, int k) {

    priority_queue<int, vector<int>, greater<int>> mini;

    for (int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for (int j = i; j < arr.size(); j++) {
            sum += arr[j];

            // Insert into min-heap with K size
            if (mini.size() < k) {
                mini.push(sum);
            } else {

                // if the current element contain the greater sum then pop the
                // top element
                if (sum > mini.top()) {
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    return mini.top();
}

// TC: O(N^2 * logK)
// SC: O(K)
```

<hr>
