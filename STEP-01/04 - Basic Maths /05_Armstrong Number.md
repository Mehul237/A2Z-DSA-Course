```cpp

#include<bits/stdc++.h>
using namespace std;


bool ArmstrongNumber(int n) {

  int originalno = n;
  int count = 0;
  int temp = n;
  
  // 1. cnt the no. of digit
  while (temp != 0) {
    count++;
    temp = temp / 10;
  }

  int sumofpower = 0;

  // 2. multiply with lastDigit * cnt
  while (n != 0) {
    int lastDigit = n % 10;
    sumofpower += pow(lastDigit, count);
    n /= 10;
  }
  return (sumofpower == originalno);
}



int main() {

  int num = 1634;
  cout << ( ArmstrongNumber(num) ? "Yes" : "No" );

  return 0;
}


// TC: O(n)
//  - where n is the number of digits since we need to traverse every digit and
//    add digits raised to power no. of digits to sum.
//
// SC: O(1) since no extra space is required
```


<br>

[Armstrong number -- GFG](https://www.geeksforgeeks.org/problems/armstrong-numbers2727/1)

<hr>

```cpp

class Solution {
  public:
    string armstrongNumber(int n) {
        int temp = n;
        int sum = 0;      // cube of digits
        
        while(temp != 0) {
            int lastDigit = temp % 10;
            sum += (lastDigit * lastDigit * lastDigit);
            temp /= 10;   // Update temp to remove last digit
        }
        return sum == n? "true": "false";
    }
};

// TC: O(1)
// SC: O(1)
```

<hr>
