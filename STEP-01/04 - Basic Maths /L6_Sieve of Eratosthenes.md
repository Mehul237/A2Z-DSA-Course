
[1. Codebeyond - Striver](https://youtube.com/playlist?list=PLN4aKSfpk8TQDJz7KLiwGFgnoUUwzfl1i&feature=shared) <br>
[2. Codeadda - ITNU](https://codeadda.netlify.app/blog/10)

```cpp

#include <bits/stdc++.h>
using namespace std;


void sieveOfEratosthenes(int n) {
  
  // Create a boolean vector "is_prime[0..n]" and initialize all entries it as true. 
  // A value in is_prime[i] will finally be false if i is Not a prime, else true.
  vector<bool> is_prime(n+1, true);
  is_prime[0] = is_prime[1] = false;

  // Iterate through numbers starting from 2 up to square root of n
  for(int i=2; i*i<=n; i++) {
    // If is_prime[i] is true, it means i is a prime number
    if (is_prime[i]) {
      // Mark all multiples of i as non-prime
      for(int j=i*i; j<=n; j += i)
        is_prime[j] = false;
    }
  }

  
  // Print all prime numbers
  cout << "Prime numbers smaller than or equal to " << n << " are: ";
  for(int p=2; p<=n; p++) {
    if (is_prime[p])
      cout << p << " ";
  }
  cout << "\n";

}

// 1. O(N): for pre-computation vector initialize with 1
// 2. N log (logN): For checking from 2 to till sqrt N and 
//                  if it is prime then mark multiple for i are false
// 3. O(N): for printing the ans


// TC: O(N) + O(N log (logN) )
// SC: O(N), for Creating a boolean vector of size (N+1) to store whether each number is prime or not.



int main() {
  
  int n;
  cout << "Enter the value of N: ";
  cin >> n;

  sieveOfEratosthenes(n);
  return 0;

}
```
