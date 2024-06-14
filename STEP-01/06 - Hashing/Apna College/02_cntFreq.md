## Q1: Count frequency of elements

![Screenshot 2024-06-14 164823](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/c0f88898-f25e-4d46-99da-dc4cf3596a31)

![Screenshot 2024-06-14 164838](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/d21fcd8d-e90f-4e7f-b64c-f39ba3718213)


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



int main() {

    // Q: Count frequency of elements

    // 
    int n;
    cin >> n;

    vi a(n);
    map<int, int> mp;

    rep(i, 0, n) {
        cin >> a[i];
    }

    rep(i, 0, n) {
        mp[a[i]]++;
    }

    for(auto it : mp) {
        cout << it.first << " " << it.second << "\n";
    }


    return 0;
}

```

<hr>
<br>
