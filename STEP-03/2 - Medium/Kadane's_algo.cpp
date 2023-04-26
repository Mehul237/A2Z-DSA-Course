

/*
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
 Brute force Approach:
 
 Intuition:
   - We will check the sum of every possible subarray and consider the maximum among them. To get every possible subarray sum, we will be using three nested loops. 
   - The first loops(say i and j) will iterate over every possible starting index and ending index of a subarray.
      -* Basically, in each iteration, the subarray range will be from index i to index j. 
   - Using another loop we will get the sum of the elements of the subarray [i…..j]. Among all values of the sum calculated, we will consider the maximum one.
   
Time Complexity:  O(N3), where N = size of the array.
         Reason:  We are using three nested loops, each running approximately N times.
Space Complexity:  O(1) as we are not using any extra space.
 ---------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // subarray = arr[i.....j]
            int sum = 0;

            //add all the elements of subarray:
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }

            maxi = max(maxi, sum);
        }
    }

    return maxi;
}
  
  
  
  
  
  /*
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
  Better  Approach:
  
Intuition: If we carefully observe, 
we can notice that to get the sum of the current subarray we just need to add the current element(i.e. arr[j]) to the sum of the previous subarray i.e. arr[i….j-1].

   - Assume previous subarray = arr[i……j-1]
     current subarray = arr[i…..j]
     Sum of arr[i….j] = (sum of arr[i….j-1]) + arr[j]
     
   ->  This is how we can remove the third loop and while moving j pointer, we can calculate the sum.
   
   
Approach:
The steps are as follows,
   - First, we will run a loop(say i) that will select every possible starting index of the subarray. 
            The possible starting indices can vary from index 0 to index n-1(n = array size).
   - Inside the loop, we will run another loop(say j) that will signify the ending index as well as the current element of the subarray. 
            For every subarray starting from index i, the possible ending index can vary from index i to n-1(n = size of the array).
   - Inside loop j, we will add the current element to the sum of the previous subarray.
            i.e. sum = sum + arr[j]. Among all the sums the maximum one will be the answer.
   
Time Complexity: O(N2), where N = size of the array.
         Reason: We are using two nested loops, each running approximately N times.
Space Complexity: O(1) as we are not using any extra space.
 ---------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/


int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            // current subarray = arr[i.....j]

            //add the current element arr[j]
            // to the sum i.e. sum of arr[i...j-1]
            sum += arr[j];

            maxi = max(maxi, sum); // getting the maximum
        }
    }

    return maxi;
}






/*
-------------------------------------------------------------------------------------------------------------------------------------------------------
  Optimal appraoch: Kadane's algorithm
  
 Intuition:
    The intuition of the algorithm is not to consider the subarray as a part of the answer if its sum is less than 0. 
    -> A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum.
  
 Approach:
  The steps are as follows:
      - We will run a loop(say i) to iterate the given array.
      - Now, while iterating we will add the elements to the sum variable and consider the maximum one.
      - If at any point the sum becomes negative we will set the sum to 0 as we are not going to consider it as a part of our answer.
 
Time Complexity: O(N), where N = size of the array.
         Reason: We are using a single loop running N times.
Space Complexity: O(1) as we are not using any extra space.


-------------------------------------------------------------------------------------------------------------------------------------------------------
*/

long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
}



 // GFG - https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/0?company[]=Visa&company[]=Visa&page=2&query=company[]Visapage2company[]Visa

class Solution{
    public:
    long long maxSubarraySum(int arr[], int N){
        
        long long currentSum = 0;
        long long maxiSum = LONG_MIN;
        
        for(int i=0; i<N; i++) {
            currentSum += arr[i];
       
           if(currentSum > maxiSum) {
                maxiSum = currentSum;
            }
         // or   maxiSum = max(currentSum, maxiSum);
        
           if (currentSum < 0) {
                currentSum = 0;
            }
        }
        return maxiSum;
    }
};






























/*
---------------------------------------------------------------------------------------------------------------------------------------------
Follow-up question (Printing the subarray with maximum sum): 

There might be more than one subarray with the maximum sum. We need to print any of them.

Intuition: Our approach is to store the starting index and the ending index of the subarray. 
           Thus we can easily get the subarray afterward without actually storing the subarray elements.

If we carefully observe our algorithm, 
  we can notice that the subarray always starts at the particular index where the sum variable is equal to 0, and at the ending index, 
   the sum always crosses the previous maximum sum(i.e. maxi).

 - So, we will keep a track of the starting index inside the loop using a start variable.
 ->  We will take two variables ansStart and ansEnd initialized with -1. And when the sum crosses the maximum sum, 
     we will set ansStart to the start variable and ansEnd to the current index i.e. i.
     
The rest of the approach will be the same as Kadane’s Algorithm.


Time Complexity: O(N), where N = size of the array.
         Reason: We are using a single loop running N times.
Space Complexity: O(1) as we are not using any extra space.
---------------------------------------------------------------------------------------------------------------------------------------------
*/



long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {

        if (sum == 0) start = i; // starting index
        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    //printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "]\n";

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
}
