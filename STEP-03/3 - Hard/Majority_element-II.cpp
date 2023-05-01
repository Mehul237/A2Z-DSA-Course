
/*

-----------------------------------------------------------------------------------------------------------------
 Brute-force approach:                                                                                          +
 - We will run a loop that will select the elements of the array one by one.                                    +
 - Now, for each unique element, we will run another loop and count its occurrence in the given array.          +
 - If any element occurs more than the floor of (N/3), we will include it in our answer.                        +
 - While traversing if we find any element that is already included in our answer, we will just skip it.        +
                                                                                                                +
 Time Complexity: O(N2), where N = size of the given array.                                                     +
                                                                                                                +
Reason:                                                                                                         +
 - For every element of the array the inner loop runs for N times.                                              +
   And there are N elements in the array. So, the total time complexity is O(N2).                               +
                                                                                                                +
Space Complexity: O(1) as we are using a list that stores a maximum of 2 elements.                              +
                  The space used is so small that it can be considered constant.                                +
-----------------------------------------------------------------------------------------------------------------

*/

vector<int> majorityElement(vector<int> v) {
    int n = v.size(); //size of the array
    vector<int> ls; // list of answers

    for (int i = 0; i < n; i++) {
        //selected element is v[i]:
        // Checking if v[i] is not already
        // a part of the answer:
        if (ls.size() == 0 || ls[0] != v[i]) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                // counting the frequency of v[i]
                if (v[j] == v[i]) {
                    cnt++;
                }
            }

            // check if frquency is greater than n/3:
            if (cnt > (n / 3))
                ls.push_back(v[i]);
        }

        if (ls.size() == 2) break;
    }

    return ls;
}










/*

-------------------------------------------------------------------------------------------------------------------------------
   Better Approach (Using Hashing):                                                                                          +
 Intuition:                                                                                                                  +
   Use a better data structure to reduce the number of look-up operations and hence the time complexity.                     +
   Moreover, we have been calculating the count of the same element again and again – so we have to reduce that also.        +
                                                                                                                             +
Approach:                                                                                                                    +
                                                                                                                             +
The steps are as follows:                                                                                                    +
 - Use a hashmap and store the elements as <key, value> pairs.                                                               +
    (Can also use frequency array based on the size of nums).                                                                +
 - Here the key will be the element of the array and the value will be the number of times it occurs.                        +
 - Traverse the whole array and update the occurrence of each element.                                                       +
 - After that, check the map if the value for any element is greater than the floor of N/3.                                  +
         If yes, include it in the list.                                                                                     +
         Else iterate forward.                                                                                               +
 - Finally, return the list.                                                                                                 +
                                                                                                                             +
Time Complexity: O(N*logN), where N = size of the given array.                                                               +
Reason: We are using a map data structure. Insertion in the map takes logN time.                                             +
       And we are doing it for N elements. So, it results in the first term O(N*logN).                                       +
       If we use unordered_map instead,                                                                                      +
       the first term will be O(N) for the best and average case and for the worst case, it will be O(N2).                   +
                                                                                                                             +
Space Complexity: O(N) as we are using a map data structure. We are also using a list that stores a maximum of 2 elements.   +
                  That space used is so small that it can be considered constant.                                            +
------------------------------------------------------------------------------------------------------------------------------

*/


vector<int> majorityElement(vector<int> v) {
    int n = v.size(); //size of the array
    vector<int> ls; // list of answers

    //declaring a map:
    map<int, int> mpp;

    // least occurrence of the majority element:
    int mini = int(n / 3) + 1;

    //storing the elements with its occurnce:
    for (int i = 0; i < n; i++) {
        mpp[v[i]]++;

        //checking if v[i] is
        // the majority element:
        if (mpp[v[i]] == mini) {
            ls.push_back(v[i]);
        }
        if (ls.size() == 2) break;
    }

    return ls;
}







/*
----------------------------------------------------------------------------------------------------------------------------
  Optimal Approach (Extended Boyer Moore’s Voting Algorithm):                                                              +
                                                                                                                           +
 Approach:                                                                                                                 +
STEP-1: Initialize 4 variables:                                                                                            +
        - cnt1 & cnt2 –  for tracking the counts of elements                                                               +
        - el1 & el2 – for storing the majority of elements.                                                                +
                                                                                                                           +
STEP-2: Traverse through the given array                                                                                   +
                                                                                                                           +
 - If cnt1 is 0 and the current element is not el2 then store the current element of the array as el1 along                +
   with increasing the cnt1 value by 1.                                                                                    +
 - If cnt2 is 0 and the current element is not el1 then store the current element of the array as el2 along                +
   with increasing the cnt2 value by 1.                                                                                    +
 - If the current element and el1 are the same increase the cnt1 by 1.                                                     +
 - If the current element and el2 are the same increase the cnt2 by 1.                                                     +
 - Other than all the above cases: decrease cnt1 and cnt2 by 1.                                                            +
                                                                                                                           +
STEP-3: The integers present in el1 & el2 should be the result we are expecting. So, using another loop,                   +
 we will manually check their counts if they are greater than the floor(N/3).                                              +
                                                                                                                           +
                                                                                                                           +
Intuition:                                                                                                                 +
  - If the array contains the majority of elements, their occurrence must be greater than the floor(N/3).                  +
 Now, we can say that the count of minority elements and majority elements is equal up to a certain point in the array.    +
  - So when we traverse through the array we try to keep track of the counts of elements and the elements themselves       +
 for which we are tracking the counts.                                                                                     +
                                                                                                                           +
  - After traversing the whole array, we will check the elements stored in the variables.                                  +
    Then we need to check if the stored elements are the majority elements or not by manually checking their counts.       +
                                                                                                                           +    
 Time Complexity: O(N) + O(N), where N = size of the given array.                                                          + 
Reason: The first O(N) is to calculate the counts and find the expected majority elements.                                 +
        The second one is to check if the calculated elements are the majority ones or not.                                +
                                                                                                                           + 
Space Complexity: O(1) as we are only using a list that stores a maximum of 2 elements.                                    +
                  The space used is so small that it can be considered constant.                                           +
----------------------------------------------------------------------------------------------------------------------------
*/

vector<int> majorityElement(vector<int> v) {
    int n = v.size(); //size of the array

    int cnt1 = 0, cnt2 = 0; // counts
    int el1 = INT_MIN; // element 1
    int el2 = INT_MIN; // element 2

    // applying the Extended Boyer Moore's Voting Algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != v[i]) {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && el1 != v[i]) {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1) cnt1++;
        else if (v[i] == el2) cnt2++;
        else {
            cnt1--, cnt2--;
        }
    }

    vector<int> ls; // list of answers

    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el1) cnt1++;
        if (v[i] == el2) cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini) ls.push_back(el1);
    if (cnt2 >= mini) ls.push_back(el2);

    // Uncomment the following line
    // if it is told to sort the answer array:
    // sort(ls.begin(), ls.end()); //TC --> O(2*log2) ~ O(1);

    return ls;
}


