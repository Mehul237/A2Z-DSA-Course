
/*
--------------------------------------------------------------
Brute force -: Using Sorting, No duplicates present only work
Commplexity 
     -> TC : O(N logN)
     -> SC : O(1)
--------------------------------------------------------------
*/


void SlargestSsmallest(int arr[], int n) {
    if(n==0 || n==1)
        cout<<-1<<" "<<-1<<endl;  // edge case when only one element is present in array
   
    sort(arr, arr+n);
  
    int small = arr[1];
    int large = arr[n-2];
  
    cout << "Second smallest is " << small << "\n";
    cout << "Second largest is " << large << "\n";
}





/*
--------------------------------------------------------------
Better approach -: Using largest, Slargest variable
Commplexity 
     -> TC : O(N), We do two linear traversals in our array
     -> SC : O(1)
--------------------------------------------------------------
*/


void SlargestSsmallest (int arr[], int n) {
    if(n==0 || n==1)
        cout<<-1<<" "<<-1<<endl;  // edge case when only one element is present in array
   
    int small = INT_MAX, second_small = INT_MAX;
    int large = INT_MIN, second_large = INT_MIN;
    int i;
  
    for(i=0; i<n; i++) {
        small = min(small, arr[i]);
        large = max(large, arr[i]);
    }
  
    for(i=0;i<n;i++) {
        if(arr[i] < second_small && arr[i] != small)
            second_small=arr[i];
        if(arr[i] > second_large && arr[i] != large)
            second_large=arr[i];
    }

    cout << "Second smallest is "<< second_small << "\n";
    cout << "Second largest is "<< second_large << "\n";
}


// GFG -> https://practice.geeksforgeeks.org/problems/second-largest3735/1

 int print2largest(int arr[], int n) {
	   
     int largest = INT_MIN;  
     int slargest = INT_MIN;  
     
     for(int i=0; i<n; i++) {
        largest = max(largest, arr[i]);
     }
     
     for(int i=0; i<n; i++) {
          if(arr[i] > slargest && arr[i] != largest) {
             slargest = arr[i];
            }
            else if (slargest == INT_MIN) {   // largest == slargest
               slargest = -1;
            }
        }
        return slargest;
   }
};





/*
--------------------------------------------------------------
Optimal approach -: 

Approach:
We would require four variables: small,second_small, large, and second_large. Variable small and second_small are initialized to INT_MAX while large and second_large are initialized to INT_MIN.

Second Smallest Algo:
If the current element is smaller than ‘small’, then we update second_small and small variables
Else if the current element is smaller than ‘second_small’ then we update the variable ‘second_small’
Once we traverse the entire array, we would find the second smallest element in the variable second_small.
Here’s a quick demonstration of the same.

Second Largest Algo:
If the current element is larger than ‘large’ then update second_large and large variables
Else if the current element is larger than ‘second_large’ then we update the variable second_large.
Once we traverse the entire array, we would find the second largest element in the variable second_large.
Here’s a quick demonstration of the same

Commplexity 
     -> TC : O(N), Single-Pass Solution
     -> SC : O(1)
--------------------------------------------------------------
*/



int secondSmallest(int arr[], int n) {
    if(n<2)
        return -1;
  
    int small = INT_MAX;
    int second_small = INT_MAX;
    
    for(int i=0; i<n; i++) {
       if(arr[i] < small) {
          second_small = small;
          small = arr[i];
       }
       else if(arr[i] < second_small && arr[i] != small) {
          second_small = arr[i];
       }
    }
   return second_small;     
}


int secondLargest(int arr[], int n) {
	if(n<2)
	   return -1;
  
    int large = INT_MIN, second_large = INT_MIN;
    
    for (int i = 0; i < n; i++)  {
        if (arr[i] > large) {
            second_large = large;
            large = arr[i];
        }
 
        else if (arr[i] > second_large && arr[i] != large) {
            second_large = arr[i];
        }
    }
    return second_large;                
}
