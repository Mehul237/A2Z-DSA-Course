
/*
------------------------------------
Brtue  force approach: Sorting
 (even if it is not the expected solution here but it can be considered as one of the approaches). 
 Since the array contains only 3 integers, 0, 1, and 2. Simply sorting the array would arrange the elements in increasing order.

 Time Complexity: O(N*logN)
 Space Complexity: O(1)
------------------------------------
*/





/*
---------------------------------------------------------------------------------------------------------------------------------------------------------------
 Better approach: Keeping count of values

Intuition: 
Since in this case there are only 3 distinct values in the array so it’s easy to maintain the count of all, Like the count of 0, 1, and 2. 
This can be followed by overwriting the array based on the frequency(count) of the values.

Approach: 
 - Take 3 variables to maintain the count of 0, 1 and 2.
 - Travel the array once and increment the corresponding counting variables
    ( let’s consider count_0 = a, count_1 = b, count_2 = c )

 - In 2nd traversal of array, we will now over write the first ‘a’ indices / positions in array with ’0’, the next ‘b’ with ‘1’ and the remaining ‘c’ with ‘2’.
 
 Time Complexity: O(N) + O(N), where N = size of the array. 
   First O(N) for counting the number of 0’s, 1’s, 2’s, and 
   second O(N) for placing them correctly in the original array.

Space Complexity: O(1) as we are not using any extra space.
 ---------------------------------------------------------------------------------------------------------------------------------------------------------------
*/


void sortArray(vector<int>& arr, int n) {
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) cnt0++;
        else if (arr[i] == 1) cnt1++;
        else cnt2++;
    }

    //Replace the places in the original array:
    for (int i = 0; i < cnt0; i++) arr[i] = 0; // replacing 0's

    for (int i = cnt0; i < cnt0 + cnt1; i++) arr[i] = 1; // replacing 1's

    for (int i = cnt0 + cnt1; i < n; i++) arr[i] = 2; // replacing 2's

}




/*
--------------------------------------------------------------------------------------------------------------------------------------------------------------
  Optimal Approach: Dutch National flag algorithm
  
 Approach:
         Note: Here in this tutorial we will work based on the value of the mid pointer.

 The steps will be the following:
      - First, we will run a loop that will continue until mid <= high.
      - There can be three different values of mid pointer i.e. arr[mid]
       
         * If arr[mid] == 0, we will swap arr[low] and arr[mid] and will increment both low and mid. Now the subarray from index 0 to (low-1) only contains 0.
         * If arr[mid] == 1, we will just increment the mid pointer and then the index (mid-1) will point to 1 as it should according to the rules.
         * If arr[mid] == 2, we will swap arr[mid] and arr[high] and will decrement high. Now the subarray from index high+1 to (n-1) only contains 2.
In this step, we will do nothing to the mid-pointer as even after swapping, the subarray from mid to high(after decrementing high) might be unsorted. 
So, we will check the value of mid again in the next iteration.
     - Finally, our array should be sorted.
     
 -------------------------------------------------------------------------------------------------------------------------------------------------------------
*/


void sortArray(vector<int>& arr, int n) {

    int low = 0, mid = 0, high = n - 1; // 3 pointers

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}


