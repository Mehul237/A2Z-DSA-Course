
/*
---------------------------------------------------------------
 Brute force approach - Using set + Iteration with all elements
 
   TC -> 0(N logN + O(N)
   SC -> 0(N), While all element are unique
---------------------------------------------------------------
*/


int removeDuplicates(int arr[], int size) 
{
  set <int> st;  
  for (int i=0; i<size; i++) {
    st.insert(arr[i]);         // O(N logN)
  }
  
  int index = 0;
  
  for (int it: st) {         // O(N)
    arr[index++] = it;
    // index++;
  }
  return index;
}





/*
------------------------------
 Optimal approach - 2 Pointer
 
   TC -> 0(N)
   SC -> 0(1)
------------------------------
*/


int removeDuplicates(int arr[], int size)
{
  int firsti = 0;
  for (int secondj = 1; secondj < size; secondj++) {
    if (arr[firsti] != arr[secondj]) {
      firsti++;                          // arr[firsti+1] = arr[secondj]
      arr[firsti] = arr[secondj];        // first++;
    }
  }
  return firsti + 1;
}
