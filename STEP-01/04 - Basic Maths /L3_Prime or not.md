
## Prime number:
- A number which is divisible by 1 and itself and the total no. of divisor is 2
- Ex: 2 3 5 7 11 13 17 19 23
- Edge case for 1 and 0: 1, 1 and 1 itself but divisor is only 1

```cpp

#include <bits/stdc++.h>
using namespace std;


bool isPrime_Brute(int N) {
  for (int i = 2; i<N; i++) {
    if (N % i == 0) {
      return false;
    }
  }
  return true;
}
// TC: O(N)
// SC: O(1)


bool isPrime_Optimal(int N) {
  for (int i = 2; i*i<N; i++) {
    if (N % i == 0) {
      return false;
    }
  }
  return true;
}
// TC: O(sqrt)
// SC: O(1)



int main() {

  int n1 = 237;
  int n2 = 11;
  
  bool ans1 = isPrime_Brute(n1);
  cout << ( (n1 != 1 && ans1 == true) ? "Prime Number" : "Non-Prime Number") << "\n";

  bool ans2 = isPrime_Optimal(n2);
  cout << ( (n2 != 1 && ans2 == true) ? "Prime Number" : "Non-Prime Number");

  return 0;
}

```
