
[ Intersection Of Two Sorted Arrays (CN) -- Optimal (2-Pointer)](https://www.codingninjas.com/studio/problems/intersection-of-2-arrays_1082149)


```cpp

#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m){

	int i = 0;
	int j = 0;
	vector<int> ans;
	
	while (i < n && j < m) {
		if (arr1[i] <arr2[j]) {
			i++;
		} 
		else if (arr1[i] > arr2[j]) {
			j++;
		} else {
			ans.push_back(arr1[i]);
			i++;
			j++;
		}
	}
	return ans;
}

```
