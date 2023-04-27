
/*
------------------------------------------------------------------------------------------------------------
 Brute Force:                                                                                              +
                                                                                                           +
 Intuition:                                                                                                +
 - Just a common fact that we need to compare elements in order to find the greatest is more than enough.  +
                                                                                                           +
 Time Complexity: O(N^2)                                                                                   +
   - Since there are nested loops being used, at the worst case n^2 time would be consumed.                +
Space Complexity: O(N)                                                                                     +
   - There is no extra space being used in this approach.                                                  +
     But, a O(N) of space for ans array will be used in the worst case.                                    +
 ----------------------------------------------------------------------------------------------------------- 
*/

vector<int> printLeadersBruteForce(int arr[], int n) {

  vector<int> ans;
  
  for (int i = 0; i < n; i++) {
    bool leader = true;

    //Checking whether arr[i] is greater than all 
    //the elements in its right side
    for (int j = i + 1; j < n; j++)
      if (arr[j] > arr[i]) {
          
        // If any element found is greater than current leader
        // curr element is not the leader.
        leader = false;
        break;
      }

    // Push all the leaders in ans array.
    if (leader)
    ans.push_back(arr[i]);
  } 
  
  return ans;
}





/*
--------------------------------------------------------------------------
   Optimal Method:                                                       +
                                                                         +
 Time Complexity: O(N)                                                   +
  - Since the array is traversed single time back to front,              +
    it will consume O(N) of time where N = size of the array.            +
                                                                         +
Space Complexity: O(N)                                                   +
  - There is no extra space being used in this approach.                 +
   But, a O(N) of space for ans array will be used in the worst case.    +
--------------------------------------------------------------------------
*/

vector<int> printLeaders(int arr[], int n) {

  vector<int> ans;
  
 // Last element of an array is always a leader,
 // push into ans array.
 int max = arr[n - 1];
 ans.push_back(arr[n-1]);

  // Start checking from the end whether a number is greater
  // than max no. from right, hence leader.
  for (int i = n - 2; i >= 0; i--)
    if (arr[i] > max) {
      ans.push_back(arr[i]);
      max = arr[i];
    }

  
  return ans;
}
