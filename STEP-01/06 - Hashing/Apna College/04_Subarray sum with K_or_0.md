## Number of Subarrays with Sum Zero

![Screenshot 2024-06-14 160503](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/1b6221f5-188c-43b0-8f52-1110a4aa9c06)

<hr>

![Screenshot 2024-06-14 160626](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/f8b1be60-a878-4fe4-9979-4f4ee3e9ad7a)

<hr>


![Screenshot 2024-06-14 160728](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/7f1e5419-e355-4de4-a7db-9841b41967b8)

![Screenshot 2024-06-14 160911](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/52c4c292-14bb-40cd-af91-88f4d33a1128)

![Screenshot 2024-06-14 160935](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/15ea0ecf-4adc-4c75-ae0c-5896476353b6)

<hr>

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

    int n;
    cin >> n;

    vector<int> a(n);

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    map<int, int> cnt;
    int preFixsum = 0;

    for(int i=0; i<n; i++) {
        preFixsum += a[i];
        cnt[preFixsum]++;
    }

    int ans = 0;
    for(auto it: cnt) {
        int c = it.second;
        ans += (c*(c-1))/2;

        if(it.first == 0) {
            ans += it.second;
        }
    }
    cout << ans << "\n";
    
    return 0;
}

```

<hr>
<br>
