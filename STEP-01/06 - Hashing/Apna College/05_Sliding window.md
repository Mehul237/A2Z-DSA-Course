



## Sliding Window Technique,

![Screenshot 2024-06-14 163005](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/5b89ee77-60fa-418a-a7a9-b9b328952652)

![Screenshot 2024-06-14 163018](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/9acc9edf-ba82-471d-b9fd-9c1fc6ef2eca)

![Screenshot 2024-06-14 163029](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/3eae5fef-0b41-4af8-8adc-c5c4cd604226)

![Screenshot 2024-06-14 163038](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/cec368a4-478e-4ca9-b7bb-4cdeca86a6a0)

![Screenshot 2024-06-14 163118](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/e1ad4b16-b2ea-40ea-9729-0b6a4063ce3e)

![Screenshot 2024-06-14 163226](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/b5db67e4-7d31-4411-b90f-7e52f760acb8)


```cpp

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define vi vector<int>
#define pii pair<int, int>
#define ff first
#define ss second
#define vii vector<pii>
#define rep(i, a, b) for(int i=a; i<b; i++)
#define setBits(x) builtin_popcount(x)

#define nline "\n"
const int MOD = 1e9 + 7;


// https://www.geeksforgeeks.org/number-subarrays-sum-exactly-equal-k/


int main() {

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    int sum = 0;
    int ans = INT_MAX;

    // 1. First k element sum
    for(int i=0; i<k; i++) {
        sum += a[i];
    }

    // cout << sum << " ";
    ans = min(sum, ans);

    // 2. sum - prevSum + curSumIncrease
    for(int i=1; i<n-k+1; i++) {

        sum -= a[i-1];    // prevSum
        sum += a[i+k-1];  // curSumIncrease

        // cout << sum << " ";
        ans = min(sum, ans);
    }
    
    // cout << "\n";
    cout << ans << "\n";
    
    return 0;
}

```
