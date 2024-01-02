
## [GFG - Who will win](https://practice.geeksforgeeks.org/problems/who-will-win-1587115621/1) 

```cpp
class Solution {
    public:
  
    // K: element to be search
    int searchInSorted(int arr[], int size, int K) { 
       for(int i=0; i<size; i++) {
           if(arr[i] == K) {
             return 1;          // Found return 1 or return index at element present
           }
       }
       return -1;               // Not found element then return -1
    }
};

```



## [Coding Ninja - Linear search](https://www.codingninjas.com/codestudio/problems/linear-search_6922070?leftPanelTab=0) 

```cpp

int linearSearch(int n, int num, vector<int> &arr) {
    for(int i=0; i<n; i++) {
        if(arr[i] == num) {
            return i;
        }
    }
    return -1;
}

```
