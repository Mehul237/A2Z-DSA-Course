
### L8. XOR of Numbers in a Given Range

```cpp

#include <bits/stdc++.h>
using namespace std;


// 1. Simple for loop with xor operation
int xor1toN_P1(int n) {
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans ^= i;
    }
    return ans;
}
// TC: O(N)
// SC: O(1)


// 2. Observation and pattern recognize
int xor1toN_P2(int n) {
    if(n % 4 == 1) 
      return 1;
    else if(n % 4 == 2) 
      return n + 1;
    else if(n % 4 == 3) 
      return 0;
    else 
      return n;
}
// TC: O(1)
// SC: O(1)


// Follow up question regarding this solution,
// You don't find the xor from 1 to N, What if i twist the question and i give you two numbers
// L and R. I ask you what is the xor from L to R tell me

int xorLtoR1(int n1, int n2) {
  int ans = 0;
  for(int i=n1; i<=n2; i++) {
    ans ^= i;
  }
  return ans;
}
// TC: O(R-L+1)
// SC: O(1)


int xorLtoR2(int n1, int n2) {
    return xor1toN_P2(n1 - 1) ^ xor1toN_P2(n2);
}
// TC: O(1)
// TC: O(1)


int main() {

// 1. Find the xor for particular N
  int n1 = 5;
  int n2 = 6;
  
  cout << "XOR 1 to N, Naive: " << xor1toN_P1(n1) << "\n";
  cout << "XOR 1 to N, Optimized: " << xor1toN_P2(n2) << "\n";


// 2. Find the xor from L to R range
  int n3 = 4;
  int n4 = 8;

  cout << "XOR L to R, Naive: " << xorLtoR1(n3, n4) << "\n";
  cout << "XOR L to R, Optimized: " << xorLtoR2(n3, n4);

  return 0;
}
```
