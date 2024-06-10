
## [1st revise, Reverse first K element of Queue -- Addition of K first element](https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1)

<hr>

<img width="367" alt="image" src="https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/7b4494da-6999-40c6-a522-8eb8d475e237">

<img width="319" alt="image" src="https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/75d23d9b-99d0-48a1-ab42-9fef2109c1ce">

<hr>


```cpp

class Solution {
public:
    queue<int> modifyQueue(queue<int> q, int k) {
        // algo:
        // 1. first k element stack me daaldo and queue se hatado
        // 2. k element stack se nikalke wapas queue me daalde
        // 3. fer queue k (n-k) starting k elements, wapas queue me daalde

        stack<int> s;

        // Step-01: Fetch 1st K element from Q and push into stack
        for (int i = 0; i < k; i++) {
            int val = q.front();
            q.pop();
            s.push(val);
        }

        // Step-02: fetch elements from Stack and push into Q
        while (!s.empty()) {
            int val = s.top();
            s.pop();
            q.push(val);
        }

        // Step-03: Fetch 1st N-K elements from Q and push_back() -- insert at
        // end
        int t = q.size() - k;

        while (t--) {
            int val = q.front();
            q.pop();
            q.push(val);
        }
        return q;
    }
};


// TC: O(N)
// --- O(K) + O(K) + O(N - K)
// --- O(N) + O(N) + o(N - N)

// SC: O(K)
```

<hr>


```cpp



class Solution {
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        
        stack<int>s;
        queue<int>ans;
        
        while(k--) {
            s.push(q.front());
            q.pop();
        }

        while(!s.empty()) {
            ans.push(s.top());
            s.pop();
        }

        while(!q.empty()) {
            ans.push(q.front());
            q.pop();
        }
        return ans;
    }
};

// TC: o(N), Refer above

// SC: O(N + K)
// -- Stack for store the temporary K element
// -- After, ans is used to store the modified elements
//    Since it stores all elements of the input queue, O(N)
```

<hr>
