
[Merge two Sorted array (CN) - Brute force approach (Set, Map)](https://www.codingninjas.com/studio/problems/sorted-array_6613259?leftPanelTabValue=PROBLEM)

```cpp

#include <bits/stdc++.h>

vector < int > sortedArray(vector < int > a, vector < int > b) {
    
    int n1 = a.size();
    int n2 = b.size();

    set<int>st;

    for(int i=0; i<n1; i++) {
        st.insert(a[i]);
    }

    for(int i=0; i<n2; i++) {
        st.insert(b[i]);
    }

    vector<int>ans;

    for(auto it : st) {
        ans.push_back(it);
    }

    return ans;
}

```

<br>

[Merge two Sorted array (CN) - Optimal (2-pointer)](https://www.codingninjas.com/studio/problems/sorted-array_6613259?leftPanelTabValue=PROBLEM)


```cpp

#include <bits/stdc++.h>
using namespace std;

vector<int> sortedArray(vector<int> a, vector<int> b) {
    
    int n1 = a.size();
    int n2 = b.size();
    int i = 0;
    int j = 0;
    vector<int> ans;

    while(i<n1 && j<n2) {

        if(a[i] <= b[j]) {
            if(ans.size() == 0 || ans.back() != a[i]) {
                ans.push_back(a[i]);
            }
            i++;
        } else {

            if(ans.size() == 0 || ans.back() != b[j]) {
                ans.push_back(b[j]);
            }
            j++;
        }
    }

    // While remaining element from the a and b side then,

    while( j < n2) {
        if(ans.size() == 0 || ans.back() != b[j]) {
            ans.push_back(b[j]);
        } 
        j++;  
    }

    while( i < n1) {
        if(ans.size() == 0 || ans.back() != a[i]) {
            ans.push_back(a[i]);
        }  
        i++; 
    }
  
    return ans;
}

```
