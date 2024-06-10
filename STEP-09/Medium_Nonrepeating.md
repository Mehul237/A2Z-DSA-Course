[First non-repeating character in a stream](https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1)


```cpp

class Solution {
public:
    string FirstNonRepeating(string A) {

        unordered_map<char, int> count;   // freq find
        queue<char> q;                    // ch tracking
        string ans = "";

        for (int i = 0; i < A.length(); i++) {
            char ch = A[i];
            count[ch]++; // count increase
            q.push(ch);  // push element into queue

            while (!q.empty()) {

                // 1. repeating ch
                if (count[q.front()] > 1) {
                    q.pop();
                } else {

                    // 2. Non-repeating ch
                    ans.push_back(q.front());
                    break;
                }
            }

            // 3. queue empty
            if (q.empty()) {
                ans.push_back('#');
            }
        }
        return ans;
    }
};


```
