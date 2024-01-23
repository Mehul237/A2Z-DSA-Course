### (4) Space Optimization

```cpp

#include <bits/stdc++.h> 
using namespace std;
 
const int MOD = 1e9 + 7;

int main() {

  int n;
  cout << "Find Nth Fibonacci number: ";
  cin >> n;
  
  int first = 0;
  int second = 1;

  for(int i=2; i<=n; i++) {
    int third = (first + second) % MOD;
    first = second;
    second = third;
  }

  cout << "Fib number: " << second;

}

```

</pre>

<pre><strong>Time Complexity: </strong> O(n)
 - We are running a simple iterative loop
  
<strong>Space Complexity:</strong> O(1)
 - We are not using any extra space
  
</pre>
