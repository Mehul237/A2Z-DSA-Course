```cpp

#include <bits/stdc++.h>
using namespace std;


/*

  N = 7789, reverseNum = 0

  (1) LastDigit: 7789 % 10 = 9
      Nums:      7789 / 10 = 778

      reverseNum = (0 * 10) + 9 = 9

  (2) LastDigit: 778 % 10 = 8
      Nums:      778 / 10 = 77  (N /= 10)

      reverseNum = (9 * 10) + 8 = 98

*/


int main() {

  int N = 7789;
  int revNum = 0;

  while(N > 0) {
    int lastDigit = N % 10;
    revNum = (revNum * 10) + lastDigit;
    N = N / 10;  
  }
  cout << revNum;
  

  return 0;
}


// Time Complexity: O(n), where n is the length of the given number
// Space Complexity: O(1)

```
