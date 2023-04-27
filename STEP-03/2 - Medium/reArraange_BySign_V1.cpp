

/*
------------------------------------------------------------------------------------------------------------------------------------------------------------
  Variety - 01                                                                                                                                             +
  --------------
Brute Force Method                                                                                                                                         +
                                                                                                                                                           +
Approach:                                                                                                                                                  +
 - In this simple approach, since the number of positive and negative elements are the same,                                                               +
    we put positives into an array called “pos” and negatives into an array called “neg”. e,                                                               +
 - After segregating each of the positive and negative elements, we start putting them alternatively back into array A.                                    +
 - Since the array must begin with a positive number and the start index is 0,                                                                             +
   so all the positive numbers would be placed at even indices (2*i) and negatives at the odd indices (2*i+1),                                             +
   where i is the index of the pos or neg array while traversing them simultaneously.                                                                      +
                                                                                                                                                           +
                                                                                                                                                           +
 Time Complexity: O(N+N/2)                                                                                                                                 +
   - O(N) for traversing the array once for segregating positives and negatives and another O(N/2) for adding those elements alternatively to the array,   + 
     where N = size of the array A.                                                                                                                        +
                                                                                                                                                           +
Space Complexity:  O(N/2 + N/2) = O(N)                                                                                                                     +
   - N/2 space required for each of the positive and negative element arrays, where N = size of the array A.                                               +
                                                                                                                                                           +
                                                                                                                                                           +
                                                                                                                                                           +
 This approach uses O(N+N/2) of running time due to multiple traversals which we’ll try to optimize in the optimized approach given below.                 +
------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

  vector<int> RearrangebySign(vector<int>A, int n) {
    
       // Define 2 vectors, one for storing positive 
       // and other for negative elements of the array.
         vector<int> pos;
         vector<int> neg;
  
      // Segregate the array into positives and negatives.
         for(int i=0;i<n;i++){
      
             if(A[i]>0) pos.push_back(A[i]);
             else neg.push_back(A[i]);
         }
  
     // Positives on even indices, negatives on odd.
         for(int i=0;i<n/2;i++){
      
             A[2*i] = pos[i];
             A[2*i+1] = neg[i];
         }
         return A;  
}







/*
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Optimal Method                                                                                                                                                                                                                  +
                                                                                                                                                                                                                                + 
Approach:                                                                                                                                                                                                                       +
 - In this optimal approach, we will try to solve the problem in a single pass and try to arrange the array elements in the correct order in that pass only.                                                                    +
 - We know that the resultant array must start from a positive element so we initialize the positive index as 0 and negative index as 1 and start traversing the array such that whenever we see the first positive element,    +
   it occupies the space at 0 and then posIndex increases by 2 (alternate places).                                                                                                                                              + 
 - Similarly, when we encounter the first negative element, it occupies the position at index 1,                                                                                                                                + 
   and then each time we find a negative number, we put it on the negIndex and it increments by 2.                                                                                                                              + 
 - When both the negIndex and posIndex exceed the size of the array, we see that the whole array is now rearranged alternatively according to the sign.                                                                         + 
                                                                                                                                                                                                                                + 
 Time Complexity: O(N)                                                                                                                                                                                                          + 
   - O(N) for traversing the array once and substituting positives and negatives simultaneously using pointers, where N = size of the array A.                                                                                  +   
                                                                                                                                                                                                                                +   
Space Complexity:  O(N)                                                                                                                                                                                                         + 
   - Extra Space used to store the rearranged elements separately in an array, where N = size of array A.                                                                                                                       +      
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- 
*/

  vector<int> RearrangebySign(vector<int>A) {
    
  int n = A.size();
  
  // Define array for storing the ans separately.
  vector<int> ans(n,0);
  
  // positive elements start from 0 and negative from 1.
  int posIndex = 0, negIndex = 1;
  for(int i=0; i<n; i++) {
      
      // Fill negative elements in odd indices and inc by 2.
      if(A[i]<0) {
          ans[negIndex] = A[i];
          negIndex+=2;
      }
      
      // Fill positive elements in even indices and inc by 2.
      else{
          ans[posIndex] = A[i];
          posIndex+=2;
      }
  }  
  return ans;
}






/*
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   Variety - 02                                                                                                                                                                               +
  --------------                                                                                                                                                                              +
                                                                                                                                                                                              +
                                                                                                                                                                                              +
Intuition:                                                                                                                                                                                    +
- In this variety, the number of positive and negative numbers shall not necessarily be equal to each other in the given array.                                                               +
   So, there can be two cases possible: either the positive elements exceed the negatives or the negatives exceed the positives.                                                              +
- So, instead of using the optimal solution discussed for the variety-1 above,                                                                                                                +
  we’ll fall back to the brute force solution where we create separate arrays for storing positives and negatives and then put them back into the array alternatively.                        +
  The remaining negative or positive elements are added to the array at last.                                                                                                                 +
                                                                                                                                                                                              +
Approach:                                                                                                                                                                                     +
                                                                                                                                                                                              +
 - In this problem, first, we create a neg array and a pos array for storing all the negative and positive elements of array A separately.                                                    +
 - Now, similar to the Brute force approach for variety-1, we start putting elements of pos and neg array alternatively back into array A.                                                    +
 - Since the array must begin with a positive number and the start index is 0, so all the positive numbers would be placed at even indices (2*i) and negatives at the odd indices (2*i+1),    +
   where i is the index of the pos or neg array while traversing them simultaneously.                                                                                                         +
 - After all the elements are added to the index where positives were equal to the negatives,                                                                                                 +
   we now put all the remaining elements ( whether positive or negative) at the last of the array by running a single loop from pos.size() to neg.size()                                      +
     {if positives < negatives} or neg.size() to pos.size() {if negatives < positives}.                                                                                                       +
                                                                                                                                                                                              + 
 Time Complexity: O(2*N)                                                                                                                                                                      +
  - The worst case complexity is O(2*N) which is a combination of O(N) of traversing the array to                                                                                             +
    segregate into neg and pos array and O(N) for adding the elements alternatively to the main array.                                                                                        +
                                                                                                                                                                                              +
Explanation:                                                                                                                                                                                  +
The second O(N) is a combination of O(min(pos, neg)) + O(leftover elements).                                                                                                                  +
There can be two cases: when only positive or only negative elements are present, O(min(pos, neg)) + O(leftover) = O(0) + O(N),                                                               +
   and when equal no. of positive and negative elements are present, O(min(pos, neg)) + O(leftover) = O(N/2) + O(0).                                                                          +
So, from these two cases, we can say the worst-case time complexity is O(N) for the second part,                                                                                              +
   and by adding the first part we get the total complexity of O(2*N).                                                                                                                        +
                                                                                                                                                                                              +
Space Complexity:  O(N/2 + N/2) = O(N)                                                                                                                                                        +
 - N/2 space required for each of the positive and negative element arrays, where N = size of the array A.                                                                                    +
 ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/


 vector<int> RearrangebySign(vector<int>A, int n){
    
  // Define 2 vectors, one for storing positive 
  // and other for negative elements of the array.
  vector<int> pos;
  vector<int> neg;
  
  // Segregate the array into positives and negatives.
  for(int i=0;i<n;i++){
      
      if(A[i]>0) pos.push_back(A[i]);
      else neg.push_back(A[i]);
  }
  
  // If positives are lesser than the negatives.
  if(pos.size() < neg.size()){
      
    // First, fill array alternatively till the point 
    // where positives and negatives ar equal in number.
    for(int i=0;i<pos.size();i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
    }
    
    // Fill the remaining negatives at the end of the array.
    int index = pos.size()*2;
    for(int i = pos.size();i<neg.size();i++){
        
        A[index] = neg[i];
        index++;
    }
  }
  
  // If negatives are lesser than the positives.
  else{
      
      // First, fill array alternatively till the point 
      // where positives and negatives ar equal in number.
      for(int i=0;i<neg.size();i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
  }
    
    // Fill the remaining positives at the end of the array.
    int index = neg.size()*2;
    for(int i = neg.size();i<pos.size();i++){
        
        A[index] = pos[i];
        index++;
    }
  }
  return A;   
}
