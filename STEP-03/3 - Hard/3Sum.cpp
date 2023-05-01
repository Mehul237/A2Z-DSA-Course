
/*

----------------------------------------------------------------------------------------------------------------
Brute Force:                                                                                                   +
                                                                                                               +
Intuition:                                                                                                     +
 - While starting out, our aim must be to come up with a working solution first. Thus, given the problem,      +
   the most intuitive solution would be using three-pointers and checking for each possible triplet,           +
   whether we can satisfy the condition or not.                                                                +
                                                                                                               +
Approach:                                                                                                      +
- We keep three-pointers i,j, and k. For every triplet we find the sum of A[i]+A[j]+A[k].                      +
  If this sum is equal to zero, we’ve found one of the triplets.                                               +
  We add it to our data structure and continue with the rest.                                                  +
                                                                                                               +
  Time Complexity : O(n^3)   // 3 loops                                                                        +
                                                                                                               +
  Space Complexity : O(3*k)  // k is the no.of triplets                                                        +
----------------------------------------------------------------------------------------------------------------

*/

vector < vector < int >> threeSum(vector < int > & nums) {
  vector < vector < int >> ans;
  vector < int > temp;
  int i, j, k;
  for (i = 0; i < nums.size() - 2; i++) {
    for (j = i + 1; j < nums.size() - 1; j++) {
      for (k = j + 1; k < nums.size(); k++) {
        temp.clear();
        if (nums[i] + nums[j] + nums[k] == 0) {
          temp.push_back(nums[i]);
          temp.push_back(nums[j]);
          temp.push_back(nums[k]);
        }
        if (temp.size() != 0)
          ans.push_back(temp);
      }
    }
  }

  return ans;
}






