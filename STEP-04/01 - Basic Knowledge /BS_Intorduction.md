```cpp
#include <bits/stdc++.h>
using namespace std;

int BSFindIterative(int arr[], int N, int target) {

    int low = 0, high = N-1; 
    
    while( low <= high) {

      int mid = low + (high - low)/ 2;

      if(arr[mid]==target) {
         return mid;
      }

      else if(target > arr[mid])  {
         low = mid + 1;
      }

      else {
         high = mid - 1;
      }
    }
    return -1;
}



int BSFindRecursive(int arr[], int N, int low, int high, int target) {
   
   if(low > high) 
     return -1;
   
   int mid = (low + high) / 2; 

   if(arr[mid]==target)
     return mid;

   else if(target > arr[mid]) 
     return BSFindRecursive(arr, 7, mid+1, high, target);

   return BSFindRecursive(arr, 7, low, mid-1, target);

}



int lowerBound_Implementation(vector<int>arr, int target) {
  
   int low = 0, high = arr.size()-1;
   int ans = arr.size();

   while(low <= high) {
      int mid = low + (high-low)/ 2;
      
      // Maybe an answer
      if(arr[mid] >= target) {
         ans = mid;

         // Look for more small index on left
         high = mid -1;
      }

      else {

         // Look for right 
         low = mid + 1;
      }
   }
   return ans;
}



int upperBound_Implementation(vector<int>arr, int target) {
  
   int low = 0, high = arr.size()-1;
   int ans = arr.size();

   while(low <= high) {
      int mid = low + (high-low)/ 2;
      
      // Maybe an answer
      if(arr[mid] > target) {
         ans = mid;

         // Look for more small index on left
         high = mid -1;
      }

      else {

         // Look for right 
         low = mid + 1;
      }
   }
   return ans;
}



int main() {
   
 // 01 - BS Implementation through Iterative and Recursive way
   int arr[] = { 1, 3, 7, 9, 211, 237, 269 };
   cout << "Iterative-way: " << BSFindIterative(arr, 7, 237)  << "\n";
   cout << "Recursive-way: " << BSFindRecursive(arr, 7, 0, 7-1, 237) << "\n";


// 02 - Lower & Upper bound Implementation.

// Lower Bound
  vector<int> v1 = {1, 2, 3, 3, 5, 8, 8, 10, 10, 11};
  cout << "LowerBound-Implementation: " << lowerBound_Implementation(v1, 10) << "\n";
  cout << "In-built STL Fn: "<< lower_bound(v1.begin(), v1.end(), 10) - v1.begin() << "\n";


// Upper Bound 
  vector<int> v2 = {1, 2, 3, 3, 5, 8, 8, 10, 10, 11};
  cout << "UpperBound-Implementation: " << upperBound_Implementation(v2, 269) << "\n";   
  cout << "In-built STL Fn: "<< upper_bound(v2.begin(), v2.end(), 269) - v2.begin();
   
  return 0;
}
```
