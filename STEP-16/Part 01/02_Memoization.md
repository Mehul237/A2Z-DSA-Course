### (2) Memoization (Top-down, Main Problem to Base case, Recursion)

```cpp

// TLE DP series (CSES Problem set)

#include <bits/stdc++.h> 
using namespace std;
 
 
vector<int>dp(100, -1);

int fib(int n) {

  if(n <= 1) {
    return n;
  }
  
  if(dp[n] != -1) {
    return dp[n];
  }
  
  dp[n] = fib(n-1) + fib(n-2);
  return dp[n];
}


int main() {

  int n;
  cout << "Find Nth Fibonacci number: ";
  cin >> n;

  cout << "Fib number: " << fib(n);

}

```



```cpp

// Striver DP Series

#include <bits/stdc++.h> 
using namespace std;
 

int fib(int n, vector<int> &dp) {

  if(n <= 1) {
    return n;
  }
  
  if(dp[n] != -1) {
    return dp[n];
  }
  
  return dp[n] = fib(n-1, dp) + fib(n-2, dp);

}


int main() {

  int n;
  cout << "Find Nth Fibonacci number: ";
  cin >> n;

  vector<int> dp(n+1, -1);
  
  cout << "Fib number: " << fib(n, dp);

}

```


</pre>

<pre><strong>Time Complexity: </strong> O(n)
 - The time complexity is improved compared to the naive recursive approach
 - Since each Fibonacci number is computed only once and stored in the dp array, the time complexity is O(n)
 - This is because the algorithm needs to calculate Fibonacci numbers from 0 to n, 
   and each Fibonacci number is computed in constant time once.
  
<strong>Space Complexity:</strong> O(n)
 - The dp array is used to store intermediate results, and its size is proportional to the input value of n 
 - Therefore, the space required grows linearly with the input size

Conclusion:
 - This memoized implementation significantly improves the time complexity compared to the naive recursive approach, 
    making it more efficient for larger values of n 
 - However, the space complexity is still O(n) due to the space required for storing intermediate results in the dp vector
  
</pre>
