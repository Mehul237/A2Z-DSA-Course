
/*
----------------------------------------------------------------------------------------------------------------------------------------------------
 Brute Force:                                                                                                                                      +
                                                                                                                                                   +
Approach: We can simply sort the array and run a for loop to find the longest consecutive sequence.                                                +
                                                                                                                                                   +
Time Complexity: We are first sorting the array which will take O(N * log(N)) time and then we are running a for loop which will take O(N) time.   +
                 Hence, the overall time complexity will be O(N * log(N)).                                                                         +
Space Complexity: The space complexity for the above approach is O(1) because we are not using any auxiliary space                                 +
----------------------------------------------------------------------------------------------------------------------------------------------------

*/

int longestConsecutive(vector<int> nums) {
        if(nums.size() == 0 ) {
            return 0;
        }
        sort(nums.begin(),nums.end());
        
        int ans = 1;
        int prev = nums[0];
        int cur = 1;
        
        for(int i = 1;i < nums.size();i++) {
            if(nums[i] == prev+1) {
                cur++;
            }
            else if(nums[i] != prev) {
                cur = 1;
            }
            prev = nums[i];
            ans = max(ans, cur);
        }
        return ans;
    }




/*
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  Optimal Method:                                                                                                                                                                           +                        
                                                                                                                                                                                            +  
  Approach:                                                                                                                                                                                 +  
   - We will first push all elements in the HashSet.                                                                                                                                        +  
   - Then we will run a for loop and check for any number(x) if it is the starting number of the consecutive sequence by checking if the HashSet contains (x-1) or not.                     +
   - If ‘x’ is the starting number of the consecutive sequence we will keep searching for the numbers y = x+1, x+2, x+3, …And stop at the first ‘y’ which is not present in the HashSet.    +
  Using this we can calculate the length of the longest consecutive subsequence.                                                                                                            +
  -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

// Old Code

int longestConsecutive(vector < int > & nums) {
  set < int > hashSet;
  for (int num: nums) {
    hashSet.insert(num);
  }

  int longestStreak = 0;

  for (int num: nums) {
    if (!hashSet.count(num - 1)) {
      int currentNum = num;
      int currentStreak = 1;

      while (hashSet.count(currentNum + 1)) {
        currentNum += 1;
        currentStreak += 1;
      }

      longestStreak = max(longestStreak, currentStreak);
    }
  }

  return longestStreak;
}
