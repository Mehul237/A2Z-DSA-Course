 ### 01 - Brute force approach
 --------------------------------
 
 ### Intuition:
 - We can think of, involves the use of an extra array 

 ### Algorithm,

  ```Step-01:```  Create temp vector to stored non-zero elements from original to temp vector

  ```Step-02:```  We will copy the elements from the temp vector 1 by 1 and fill the first nz places of the original vector

  ```Step-03:```  then fill remaining places with zero (N size - nz element = zero element size)

  ```Step-04:```  Return the original vector
  
--------------------------------------------------------


<br>


 ### Implementation,
 
```cpp

#include <bits/stdc++.h>
using namespace std;

vector<int> moveZeros(int n, vector<int> arr) {

  // Step-01
  vector<int>temp;

  for(int i=0; i<n; i++) {
    if(arr[i] != 0) {
      temp.push_back(arr[i]);
    }
  }


  // Step-02

  // no. of non-zero elements
  int nz = temp.size();

  for(int i=0; i<nz; i++) {
    arr[i] = temp[i];
  }


  // Step-03

  for(int i=nz; i<n; i++) {
    arr[i] = 0;
  }
  return arr;
}



int main() {
  
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = 10;
    vector<int> ans = moveZeros(n, arr);

    for (auto &it : ans) {
        cout << it << " ";
    }
    cout << '\n';

    return 0;
}

```


<br>

--------------------------------------------------------------------------------------------------------------------
>  <em> **Time Complexity:**  </em> O(N) + O(NZ) + O(N-NZ) ~ O(2*N)  <br>
>>   Where <b> N </b> = total no. of elements, <br>
>>   <b> NZ </b> = no. of non-zero elements, <br>
>>   <b> N-NZ </b> = total no. of zeros <br>
>>
>  <b> Reason: </b>
>  1. O(N) for copying non-zero elements from the original to the temporary array.
>  2. O(X) for again copying it back from the temporary to the original array.
>  3. O(N-X) for filling zeros in the original array.
>  4. So, the total time complexity will be O(2*N).
>> 
>  <em> **Space Complexity:** </em> O(N)
>  - as we are using a temp array to solve this problem and the maximum size of the array can be N in the worst case.
>
>  <b> Reason: </b>
>  1. The temp array stores the non-zero elements.
>  2. In the worst case, all the given array elements will be non-zero.
--------------------------------------------------------------------------------------------------------------------


 ### 01 - Optimal approach
 --------------------------------

 ### Algorithm,
  ```Step-01:```   First, using a loop, we will place the pointer j. If we don’t find any 0, we will not perform the following steps <br>
  
  ```Step-02:```   After that, we will point i to index j+1 and start moving the pointer using a loop <br>
  
  ```Step-03:```   While moving the pointer i, we will do the following:  <br>
   -  If a[i] != 0 i.e. a[i] is a non-zero element:   <br>
      We will swap a[i] and a[j]. Now, the current j is pointing to the non-zero element a[i] <br>
      So, we will shift the pointer j by 1 so that it can again point to the first zero  <br>
      
  ```Step-04:```  Finally, our array will be set in the right manner



[Coding Ninja](https://www.codingninjas.com/studio/problems/ninja-and-the-zero-s_6581958)

```cpp

vector<int> moveZeros(int n, vector<int> a) {
    
    // find the zero element fist
    int j = -1;

    for(int i=0; i<n; i++) {
        if(a[i] == 0) {
            j = i;
            break;
        }
    }
    
    // nz element present in the arr
    if ( j == -1) 
      return a;
    
    for(int i=j+1; i<n; i++) {
        if(a[i] != 0) {
            swap(a[i], a[j]);
            j++;
        }
    }
    
    return a;
}

```







[Leetcode](https://leetcode.com/problems/move-zeroes/description/)

```cpp

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int j = -1;
        int n = nums.size();
        
        // Find the first zero elements, J pointer
        for(int i=0; i<n; i++) {
            if(nums[i] == 0) {
                j = i;
                break;
            }
        }
         
        // If not found any zero elements then return original vector
        if( j == -1)
          return;
        
        // Find the nz elements and perform swap. After that Also increment j++ 
        for(int i=j+1; i<n; i++) {
            if(nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

```
