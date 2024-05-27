[^ Find minimum number of coins](https://takeuforward.org/data-structure/find-minimum-number-of-coins/)

<br>

    What type of logic improved this question ?
Original value >= coins vector
- Subtract from the original value
- Add into answer

Type of variation of problem to print the answer,

    Variation 1 -- How many coins required: Length of the array
    Variation 2 -- Print the coins
 
<hr>

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    
  int V = 237;
  int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
  int n = 9;

 // Step-01: Create vector and and iterate from higher to lower
//  --- V >= coins then, 
//  1. Subtract from V and add into ans vector
    
  vector < int > ans;
  for (int i = n - 1; i >= 0; i--) {
    while (V >= coins[i]) {
      V -= coins[i];
      ans.push_back(coins[i]);
    }
  }

// Step-02: Print the answer, how many coins required
  cout<<"The minimum number of coins is "<< ans.size() << "\n";
  cout<<"The coins are " << "\n";
    
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}


// TC: O(V)
// SC: O(1)
```
