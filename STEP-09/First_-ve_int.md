[First negative integer in every window of size K](https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1)
- Variation problem: Sliding window maximum

<hr>

<img width="548" alt="image" src="https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/388452a4-4b5b-494b-b65f-92ee9defe5e3">

<img width="274" alt="image" src="https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/8eb72823-a778-45fa-8a7e-73dc72e9ff7e">

<hr>
<br>

```cpp
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    
    // 0. Created deque
    // 1. Insert first k elements (1st window -- ans)
    
    // ---- Observation ----
    // -> If you see carefully when you go to next window, 
    //    One new element added and new element removed (reason to use deque)
    
    // Because i know when a new element will be added in deque, 
    // I will call it push_back(), 
    // One no will be removed, pop.front()  (this is required)
    
    // 2. I will use the same type of loop
    // One Add and removed and i will find the answer
    // --> Front element will be the answer (need -ve int)
    
    
    
    
    deque<long long int> dq;
    vector<long long int> ans;
    
    
    // 1. Process window of k size, store the ind
    for(int i=0; i<K; i++) {
        if(A[i] < 0) {
            dq.push_back(i);
        }
    }
    
    // Store answer of first k sized window
    if(dq.size() > 0) {     // It means there is a element present
        ans.push_back( A[dq.front()] );
    } else {               // It means there no element 
        ans.push_back(0);
    }
    
    
    // 2. Process for remaining elements
    for(int i=K; i<N; i++) {
        
        // Removal part     lie b/w the window size or not
        if( !dq.empty() && i - dq.front() >= K ) {
            dq.pop_front();
        }
        
        // Addition part, store the index
        if(A[i] < 0) {
            dq.push_back(i);
        }
        
        // ans store
        if(dq.size() > 0) {
            ans.push_back( A[dq.front()] );
        } else {
            ans.push_back(0);
        }
    }
    return ans;
}

// TC: O(N)
//  - The algorithm processes each element once
//  - The insertion and removal of elements from the deque are constant time operations

// SC: O(N)
// - The space complexity includes the space used for the deque and the vector
// - The deque can hold up to K elements, so the space complexity is O(K)
// - The vector stores the results, which has a space complexity of O(N) as it stores an entry for each element
//   Overall, the space complexity is O(N).
```

<hr>



```cpp

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
        vector<long long> result;

        for (long long i=0; i<= N - K; i++) {
            long long j;
            bool found = false;
    
            for (j=i; j < i + K; j++) {
                if (A[j] < 0) {
                    result.push_back(A[j]);
                    found = true;
                    break;
                }
            }
    
            if (!found) {
                result.push_back(0);
            }
        }
        return result;                                         
 }

// TC: O(N * K)
// - The worst-case scenario occurs when every window of size K contains no negative integers,
//    leading to K iterations for each window

// SC: O(N - K + 1)
// - The result vector has a size of (N - K + 1),
//   representing the first negative integers for each window
```
