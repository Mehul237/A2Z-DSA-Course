
/*
---------------------------------------------------------------------------------------------------
Brute force Approach:

The steps are as follows:
  - We will run a loop that will select the elements of the array one by one.
  - Now, for each element, we will run another loop and count its occurrence in the given array.
  - If any element occurs more than the floor of (N/2), we will simply return it.
  
Time Complexity: O(N2), where N = size of the given array.
Reason: For every element of the array the inner loop runs for N times. 
        And there are N elements in the array. So, the total time complexity is O(N2).
Space Complexity: O(1) as we use no extra space.
--------------------------------------------------------------------------------------------------
*/

int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();

    for (int i = 0; i < n; i++) {
        //selected element is v[i]
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            // counting the frequency of v[i]
            if (v[j] == v[i]) {
                cnt++;
            }
        }

        // check if frquency is greater than n/2:
        if (cnt > (n / 2))
            return v[i];
    }
    return -1;
}



/*
---------------------------------------------------------------------------------------------------------------------------------------------
Better Approach:

Intuition: Use a better data structure to reduce the number of look-up operations and hence the time complexity. 
           Moreover, we have been calculating the count of the same element again and again – so we have to reduce that also.

Approach: 
    1 - Use a hashmap and store as (key, value) pairs. (Can also use frequency array based on the size of nums) 
    2 - Here the key will be the element of the array and the value will be the number of times it occurs. 
    3 - Traverse the array and update the value of the key. Simultaneously check if the value is greater than the floor of N/2. 
         -> If yes, return the key 
         -> Else iterate forward.
         
Time Complexity:  O(N*logN) + O(N), where N = size of the given array.
Reason: 
      We are using a map data structure. Insertion in the map takes logN time. And we are doing it for N elements. 
      So, it results in the first term O(N*logN). The second O(N) is for checking which element occurs more than floor(N/2) times.
       If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case, it will be O(N2).

Space Complexity: O(N) as we are using a map data structure.
----------------------------------------------------------------------------------------------------------------------------------------------
*/


int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();

    //declaring a map:
    map<int, int> mpp;

    //storing the elements with its occurnce:
    for (int i = 0; i < n; i++) {
        mpp[v[i]]++;
    }

    //searching for the majority element:
    for (auto it : mpp) {
        if (it.second > (n / 2)) {
            return it.first;
        }
    }
    return -1;
}





/*
-----------------------------------------------------------------------------------------------------------------------------
Optimal appraoch: 

Moore’s Voting Algorithm

Approach: 
    1 - Initialize 2 variables:
            Count –  for tracking the count of element
            Element – for which element we are counting
    2 - Traverse through the given array.   
            If Count is 0 then store the current element of the array as Element.
            If the current element and Element are the same increase the Count by 1.
            If they are different decrease the Count by 1.
    3 - The integer present in Element should be the result we are expecting
    
Time Complexity: O(N) + O(N), where N = size of the given array.

Reason: The first O(N) is to calculate the count and find the expected majority element. 
        The second one is to check if the expected element is the majority one or not.

      ** Note: If the question states that the array must contain a majority element, in that case, we do not need the second check. 
              Then the time complexity will boil down to O(N).

Space Complexity: O(1) as we are not using any extra space.

   - > Follow-up question you can try: Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
-----------------------------------------------------------------------------------------------------------------------------
*/


int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();
    int cnt = 0; // count
    int el; // Element

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]) cnt++;
        else cnt--;
    }

    //checking if the stored element
    // is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) return el;
    return -1;
}




// 
