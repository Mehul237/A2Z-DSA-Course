// next_permutation : find next lexicographically greater permutation


/*
--------------------------------------------------------------------------------------------------------------------------------------
Brute Force: Finding all possible permutations. ( Recursion and Backtracking Lecture : 12, 13 )                                      +
                                                                                                                                     +
Approach:                                                                                                                            +
 - Find all possible permutations of elements present and store them.                                                                +
 - Search input from all possible permutations.                                                                                      +
 - Print the next permutation present right after it.                                                                                +
                                                                                                                                     +
 Time Complexity :                                                                                                                   +
  -> For finding, all possible permutations, it is taking N!xN. N represents the number of elements present in the input array.      +
  -> Also for searching input arrays from all possible permutations will take N!. Therefore, it has a Time complexity of O(N!xN).    +
                                                                                                                                     +
Space Complexity :                                                                                                                   +
  -> Since we are not using any extra spaces except stack spaces for recursion calls. So, it has a space complexity of O(1).         +
--------------------------------------------------------------------------------------------------------------------------------------
*/




/*
--------------------------------------------------------------------------------------------------
 Better approach: Using C++ in-built function                                                    +
   -> C++ provides an in-built function called next_permutation()                                +
     - which directly returns the lexicographically next greater permutation of the input.       +
--------------------------------------------------------------------------------------------------
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
  
  // Array
    int arr[] = {1,3,2};  
    next_permutation(arr, arr+3);  //using in-built function of C++  
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
  
  // Vector
    vector <int> nextGreaterPermutation (vector <int> &A) {
      next_permutation (A.begin(), A.end());
      return A;
    }   
    return 0;
}









/*
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Optimal Approach:                                                                                                                                                                       +
                                                                                                                                                                                        +
The steps are the following:                                                                                                                                                            +
                                                                                                                                                                                        +
 01 - Find the break-point, i: Break-point means the first index i from the back of the given array where arr[i] becomes smaller than arr[i+1].                                         +
    -> For example, if the given array is {2,1,5,4,3,0,0}, the break-point will be index 1(0-based indexing).                                                                           +
         Here from the back of the array, index 1 is the first index where arr[1] i.e. 1 is smaller than arr[i+1] i.e. 5.                                                               +
    -> To find the break-point, using a loop we will traverse the array backward and store the index i where arr[i] is less than the value at index (i+1) i.e. arr[i+1].                +
                                                                                                                                                                                        +
02 - If such a break-point does not exist i.e. if the array is sorted in decreasing order, the given permutation is the last one in the sorted order of all possible permutations.      +
      So, the next permutation must be the first i.e. the permutation in increasing order.                                                                                              +
    -> So, in this case, we will reverse the whole array and will return it as our answer.                                                                                              +
                                                                                                                                                                                        +
 03 - If a break-point exists:                                                                                                                                                          +
      -> Find the smallest number i.e. > arr[i] and in the right half of index i(i.e. from index i+1 to n-1) and swap it with arr[i].                                                   +
      -> Reverse the entire right half(i.e. from index i+1 to n-1) of index i. And finally, return the array.                                                                           +
                                                                                                                                                                                        +
 Intuition:                                                                                                                                                                             +
    - We build up the intuition of the algorithm through the following observations (Explain in notes + Dry run)                                                                                  +
                                                                                                                                                                                        +
 Time Complexity: O(3N), where N = size of the given array                                                                                                                              +
   - Finding the break-point, finding the next greater element, and reversal at the end takes O(N) for each,                                                                            +
     where N is the number of elements in the input array. This sums up to 3*O(N) which is approximately O(3N).                                                                         +
                                                                                                                                                                                        +
Space Complexity: Since no extra storage is required. Thus, its space complexity is O(1).                                                                                               +
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/


vector<int> nextGreaterPermutation(vector<int> &A) {
    int n = A.size(); // size of the array.

    // Step 1: Find the break point:
    int ind = -1; // break point
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            // index i is the break point
            ind = i;
            break;
        }
    }

    // If break point does not exist:
    if (ind == -1) {
        // reverse the whole array:
        reverse(A.begin(), A.end());
        return A;
    }

    // Step 2: Find the next greater element
    //         and swap it with arr[ind]:

    for (int i = n - 1; i > ind; i--) {
        if (A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }

    // Step 3: reverse the right half:
    reverse(A.begin() + ind + 1, A.end());

    return A;
}
