
## L3. Minimum Bit Flips to Convert Number

```cpp

#include <bits/stdc++.h>
using namespace std;


int minBitFlip1(int start, int goal) {

    int ans = start ^ goal;
    int cnt = 0;

    for (int bit = 0; bit < 32; bit++) {
        if (ans & (1 << bit))
            cnt++;
    }
    return cnt;
}
// TC: O(31)
// SC: O(1)


int minBitFlip2(int start, int goal) {
    int ans = start ^ goal;
    int cnt = 0;

    while (ans != 0) {
        cnt += (ans & 1);
        ans >>= 1;
    }
    return cnt;
}
// TC: O ( log2 start^goal )
// SC: O(1)


int minBitFlip3(int start, int goal) {
    int ans = start ^ goal;
    int cnt = 0;

    while (ans != 0) {
        ans &= ans - 1; // ans = ans & (ans - 1);
        cnt++;
    }
    return cnt;
}
// TC: O(k), Where k is the no. of bits set in ans
// SC: O(1)


int main() {

    int n1 = 10;
    int n2 = 7;

    cout << minBitFlip3(n1, n2);

    return 0;
}

```
