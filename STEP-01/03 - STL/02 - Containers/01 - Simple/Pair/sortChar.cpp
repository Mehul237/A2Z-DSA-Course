#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nline "\n"
const int MOD = 1e9 + 7;

void sortChar(int a[], int b[], int n) {
  
  pair<int, char> p[n];

  // Input - Store the value
  for(int i=0; i<n; i++) {
    p[i] = { a[i], b[i]};
  }

  // Sort according to value
  sort(p, p+n);

  // Print second according to 1st value
  for(int i=0; i<n; i++) {
    cout << p[i].second << " ";
  }

}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // Sort one array according to other
  
  int a[3] = {10, 15, 5};
  int b[3] = {'x', 'y', 'z'};

  sortChar(a, b, 3);

  return 0;
  
}
