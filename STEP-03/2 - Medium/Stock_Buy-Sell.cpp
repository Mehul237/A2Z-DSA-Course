
/*
------------------------------------------------------------------------------------------------------------------------------------------------------
 Brute Force appraoch                                                                                                                                +
                                                                                                                                                     +
Intuition: We can simply use 2 loops and track every transaction and maintain a variable maxPro to contain the max value among all transactions.     +
                                                                                                                                                     +
Approach:                                                                                                                                            +
   - Use a for loop of ‘i’ from 0 to n.                                                                                                              +
   - Use another for loop of j from ‘i+1’ to n.                                                                                                      +
   - If arr[j] > arr[i] , take the difference and compare  and store it in the maxPro variable.                                                      +
   - Return maxPro.                                                                                                                                  +
                                                                                                                                                     +  
Time complexity: O(n^2)                                                                                                                              +  
Space Complexity: O(1)                                                                                                                               +  
------------------------------------------------------------------------------------------------------------------------------------------------------
*/


int maxProfit(vector<int> &arr) {
    int maxPro = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          if (arr[j] > arr[i]) {
            maxPro = max(arr[j] - arr[i], maxPro);
          }
        }
      }

    return maxPro;
}





/*
------------------------------------------------------------------------------------------------------------------------------------------------------
Optimal solution                                                                                                                                     +
                                                                                                                                                     +
Intuition: We will linearly travel the array. We can maintain a minimum from the start of the array and compare it with every element of the array,  +
           if it is greater than the minimum then take the difference and maintain it in max, otherwise update the minimum.                          +
                                                                                                                                                     +
Approach:                                                                                                                                            +
  - Create a variable maxPro and store 0 initially.                                                                                                  +
  - Create a variable minPrice and store some larger value(ex: MAX_VALUE) value initially.                                                           +
  - Run a for loop from 0 to n.                                                                                                                      +
  - Update the minPrice if it is greater than the current element of the array                                                                       +
  - Take the difference of the minPrice with the current element of the array and compare and maintain it in maxPro.                                 +
  - Return the maxPro.                                                                                                                               +
                                                                                                                                                     +  
Time complexity: O(n)                                                                                                                                +  
Space Complexity: O(1)                                                                                                                               +  
-------------------------------------------------------------------------------------------------------------------------------------------------------
*/


int maxProfit(vector<int> &arr) {
    int maxPro = 0;
    int n = arr.size();
    int minPrice = INT_MAX;

    for (int i = 0; i < arr.size(); i++) {
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);
    }
    
    return maxPro;
}
