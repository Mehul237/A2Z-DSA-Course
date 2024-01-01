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
