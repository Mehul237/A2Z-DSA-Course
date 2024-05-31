
## [Next Smaller element](https://www.naukri.com/code360/problems/next-smaller-element_1112581?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio)

![Screenshot 2024-05-31 115657](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/5bb347cc-0723-4f0d-9a41-69caf2c32835)
![Screenshot 2024-05-31 115718](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/a6e83a1e-d7bf-4f74-878b-e37d10729387)
![Screenshot 2024-05-31 115745](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/630e1563-049b-443e-a607-7921759f6807)
![Screenshot 2024-05-31 115808](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/153da265-a2a1-4857-8421-802a8b7dca96)
![Screenshot 2024-05-31 115822](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/590cbd72-450d-4266-9cdc-36436a6e7b46)
![Screenshot 2024-05-31 115916](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/8e775d91-595e-45c8-a9ad-a53a6aa209c8)


```cpp

// TC: O(N)
// SC: O(N)

#include <bits/stdc++.h>

vector<int> nextSmallerElement(vector<int>& arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i=n-1; i >= 0; i--) {
        int curr = arr[i];
        
        // Case-01: No elements greater than or equal to current element, pop from stack
        while (s.top() >= curr) {
            s.pop();
        }
        
        // Case-02: 
        // -- If there are elements greater than or equal to current element in the stack
        // -- Assign the top of the stack as the next smaller element for the current element
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}
```


<br>


## [Largest Rectangular Area in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/description/)
 - Variation from above question logic used
  
```cpp
// TC: O(N)
// SC: O(N)

class Solution {
private:
    vector<int> nextSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
 
            ans[i] = s.top();
            s.push(i);
        }
        return ans; 
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        
        vector<int> next(n);
        next = nextSmallerElement(heights, n);
            
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);
        
        int area = INT_MIN;
        for(int i=0; i<n; i++) {
            int l = heights[i];
            
            if(next[i] == -1) {
                next[i] = n;
            }
             int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }
};

```
