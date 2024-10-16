### (1) Using Recursion way

```cpp

#include <bits/stdc++.h> 
using namespace std;
 
int fib(int n) {

  if(n <= 1) {
    return n;
  }
  return fib(n-1) + fib(n-2);

}


int main() {

  int N;
  cout << "Find Nth Fibonacci number: ";
  cin >> N;

  cout << "Fib number: " << fib(N);

}

```

</pre>

<pre><strong>Time Complexity: </strong> O(2^n)
  - The time complexity can be expressed as O(2^n)
  - This is because each call to the fib function results in two additional recursive calls, 
    leading to an exponential growth in the number of function calls
  
<strong>Space Complexity:</strong> O(n)
  - The space complexity is O(n) due to the depth of the recursive call stack. 
  - In the worst case, the maximum depth of the call stack is n, as we make n recursive calls

Conclusion:
  - This recursive solution is not efficient for large values of n, as it leads to a significant number of redundant computations. 
  - Memoization or using an iterative approach can be more efficient for calculating Fibonacci numbers with larger values of n.
  
</pre>
