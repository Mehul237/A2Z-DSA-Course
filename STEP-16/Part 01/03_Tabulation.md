### (3) Tabulation (Bottom - Top, Base case to Main problem, Loop)

```cpp

#include <bits/stdc++.h> 
using namespace std;
 

int main() {

  int n;
  cout << "Find Nth Fibonacci number: ";
  cin >> n;

  vector<int> dp(n+1, -1);
  
  dp[0] = 0;
  dp[1] = 1;

  for(int i=2; i<=n; i++) {
    dp[i] = dp[i-1] + dp[i-2];
  }

  cout << "Fib number: " << dp[n];

}

```

</pre>

<pre><strong>Time Complexity: </strong> O(n)
 - We are running a simple iterative loop
  
<strong>Space Complexity:</strong> O(n)
 - We are using an external array of size ‘n+1’.
  
</pre>
