
// Article -> https://takeuforward.org/data-structure/find-the-largest-element-in-an-array/
// Video -> https://youtu.be/37E9ckMDdTk


class Solution {
 public:
  int largest(vector<int> &arr, int n) {
    sort(arr.begin(), arr.end());  // TC : O(N logN)

    int ans = arr.size()-1;
    return arr[ans];            // SC : O(1)
  }
};

/*
-----------------
Brute Approach
  TC : O(N logN)
  SC : O(1)
-----------------
*/


class Solution {
public:
  int largest(vector<int> &arr, int n) {
     
   int max_Var = INT_MIN;
     
    for(int i=0; i<n; i++) {
      if (arr[i] > max_Var) {   
         max_Var = arr[i];
      }
    }
    return max_Var;
  }
};

/*
-----------------
Optimal Approach
  TC : O(N)
  SC : O(1)
-----------------
*/
