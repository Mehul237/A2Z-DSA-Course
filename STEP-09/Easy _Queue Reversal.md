
## [Easy - Queue Reversal](https://www.geeksforgeeks.org/problems/queue-reversal/1)

<hr>

<img width="410" alt="image" src="https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/0c84055e-cbe3-4207-ac6f-d3680c317e24">

<hr>

```cpp
// Approach-01: Stack based
// - In stack, We insert elements into stack then pop the top elements and stored into ans which give the reverse order
// - So, Same logic apply here,
// - 1. POP elements 1 by 1 from the queue and insert into stack
//   2. POP elements from stack 1 by 1 and insert into queue

class Solution {
    public:
    
    queue<int> rev(queue<int> q) {
        
        // Step-01: POP all elements from the queue and insert in stack
        stack<int> st;
        
        while(!q.empty()) {
            int element = q.front();
            q.pop();
            st.push(element);
        }
        
        // Step-02: POP from Stack and insert in the queue, 
        // Until stack becomes empty
 
        while(!st.empty()) {
            int element = st.top();
            st.pop();
            q.push(element);
        }
        return q;
    }
};

// TC: o(N), There are 2 traversal O(N) + O(N) ~ O(N)
// SC: O(N), Created a stack n size
```

<hr>

```cpp

// Approach-02: Recursion based
// - We have to solve one case, rest will be done itself

class Solution {
    public:

    void solve(queue<int> &q) {
        if(q.empty()) {
            return;
        }
        
        int ele = q.front();
        q.pop();
    
        solve(q);
        q.push(ele);
    }

    
    queue<int> rev(queue<int> q) {
        solve(q);
        return q;
    }
};


// TC: O(N),
//  - Solve fn is called recursively for each element in the queue
//  - For each recursive call, one element is removed from the queue and pushed back

// SC: O(N)
// - In solve function, recursive calls are made,
//    but there's no extra space being used other than the function call stack
// - The maximum depth of the recursive calls is the number of elements in the queue
```

<hr>
