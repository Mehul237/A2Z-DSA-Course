
### Q2: No of ways to place the queen

```cpp
#include <bits/stdc++.h>
using namespace std;

int n;
int queen[20];  // q[i] -> Where i my q in row i

bool check(int row, int col) {
    for(int i=0; i<row; i++) {
        int prow = i;
        int pcol = queen[i];

        if(pcol == col || abs(col-pcol) == abs(row-prow)) {
            return 0;
        }
    }
    return 1;
}


int rec(int level) {

    // rec: no of ways to populate [level...n-1] row for a valid configuration
    // level: row in which we are placing the Q

    // 1. Pruning

    // 2. Base-case
    if(level == n) {
        return 1;
    }

    // 3. Compute
    int ans = 0;
    for(int col=0; col<n; col++) {

        // Check if the choice the valid
        if(check(level, col)) {
            // Place the queen
            queen[level] = col;

            // Explore the option
            ans += rec(level+1);

            // Revert placing the queen
            queen[level] = -1;
        }
    }

    // 4. return
    return ans;
}


void playBattle() {

    cin >> n;
    memset(queen, -1, sizeof(queen));
    cout << rec(0) << "\n";
}


int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t1 = 1;
 
  while(t1--) {
    playBattle();
    // 8 - 92
    // 4 - 2
  }

  return 0;
}
```
