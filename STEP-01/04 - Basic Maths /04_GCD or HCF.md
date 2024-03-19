
```cpp

// 01 - Brute force

#include<bits/stdc++.h>
using namespace std;


int main() {

   int num1 = 9, ans;
   int num2 = 12;

	for (int i = 1; i <= min(num1, num2); i++) {
		if (num1 % i == 0 && num2 % i == 0) {
			ans = i;
		}
	}
	cout << "The GCD of the two numbers is "<< ans;


  return 0;
}

//  Time Complexity: O( min(n1, n2) )
//  Space Complexity: O(1)
```

<br>

```cpp

// 02 - Optimal approach

#include<bits/stdc++.h>
using namespace std;


// -- Euclidean Algorithm --
// Logic: greater % smaller,
//        - And they go on till one of them is 0, other is GCD

// (1) It's a lots of step -- If a > b then, gcd(a,b) = gcd(a-b, b)
// (2)                                       gcd(a,b) = gcd(a%b, b)


int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}


int main() {

  int a = 20;
  int b = 40;

  while(a > 0 && b > 0) {
    if(a > b) a = a % b;
    else      b = b % a;
  }

  cout << (a == 0 ? b : a);
  cout << gcd(a, b);  // In-built: __gcd


  return 0;
}


// Time Complexity: O(logɸmin(a,b)), where ɸ is 1.61
//  - Whenever there is division happening, The no. of iterations will be in terms of logarithm.
//  - Over here, There is modulo you are reducing the no. of division the modulation operations are happening
//  - Thereby the TC will be in terms of logarithm  

// Space Complexity: O(1).

```
