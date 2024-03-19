```cpp

#include <iostream>
using namespace std;

int reverse(int num) {
  int Y = 0;
  while (num > 0) {

    // 1. Extract the last digit
      int digit = num % 10;
    // 2. Appending last digit
      Y = Y * 10 + digit;
    // 3. Shrinking num by discarding the last digit
      num = num / 10;
   }
  return Y;
}



int main() {

  int X = 237;  // 121
  int dummy = X;
  int Y = reverse(X);
  
  cout << (dummy == Y ? "Palindrome Number" : "Not Palindrome Number");

  return 0;
}

// Time Complexity: O(logN) for reversing N digits of input integer
// Space Complexity: O(1)

```
