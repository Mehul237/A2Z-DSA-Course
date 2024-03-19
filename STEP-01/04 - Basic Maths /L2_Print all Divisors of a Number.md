```cpp
#include <bits/stdc++.h>
using namespace std;


void printDivisorsBruteForce(int n) {

  cout << "The Divisors of " << n << " are: " << "\n";
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      cout << i << " ";
    }
  }
  cout << "\n";
}
// TC: O(n), because the loop has to run from 1 to n always
// SC: O(1), we are not using any extra space



void printDivisorsOptimal(int n) {

  cout << "The Divisors of " << n << " are: " << "\n";
  for (int i = 1; i <= sqrt(n); i++) {        // i*i <= n
    if (n % i == 0) {
      cout << i << " ";
      if (n / i != i) {
        cout << n / i << " ";
      }
    }
  }
  cout << "\n";
}
// TC: O(sqrt(n)), because every time the loop runs only sqrt(n) times
// SC: O(1), we are not using any extra space



int main() {

  int n1 = 36;
  printDivisorsBruteForce(n1);
  printDivisorsOptimal(n1);

  return 0;
}
```
