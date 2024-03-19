```cpp

#include <bits/stdc++.h>
using namespace std;


void powerExpo_Brute(int N1, int N2) {
  int result = 1;
  for (int i = 0; i < N2; ++i) {
    result *= N1;
  }
  cout << result << "\n";  
}
// TC: O(N)
// SC: O(1)


void powerExpo_Optimal(int n1, int n2) {
  long long ans = 1;

  while(n2 > 0) {

    // Odd nums
    if(n2 % 2 == 1) {   // 1. (n2 & 1)
      ans *= n1;        // ans = ans * n1
      n2 = n2 - 1;      // ---- not mandatory
    } 

    // Even nums
    n1 *= n1;        // n1 = n1 * n1
    n2 = n2 / 2;     // 2. n >>= 1
  }
  cout << ans << "\n";
}
// TC: O(logN)
// SC: O(1)



int main() {

  int num1 = 3;
  int num2 = 9;

  powerExpo_Brute(num1, num2);
  powerExpo_Optimal(num1, num2);

  cout << pow(num1, num2);

  return 0;
}
```
