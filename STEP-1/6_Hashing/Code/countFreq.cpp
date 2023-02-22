/*
------------------------------------------------------------------------------------------------------------------------
You are the one that is responsible for who you are!                                                                   +
6-Months of FOCUS & HARDWORK can put you 5-YEARS ahead in life. Don't Underestimate the power of CONSISTENCY & DESIRE  +
------------------------------------------------------------------------------------------------------------------------

***********************
 Mehul Thuletiya      *
 CF: Mehul_Thuletiya  *
 CC: mehul_237        *
***********************

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int 
#define nline "\n"

void solve() 
{
    
} 


int main()
{

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

/*
---------------------------
 Input the N-Size of array 
 LIMIT: 10^7
--------------------------
  */

  int n; cin>>n; int arr[n];
  
  for(int i=0; i<n; i++) { 
    cin>>arr[i];
  }

// Pre-compute
  unordered_map<int, int>mpp;
  for(int i=0; i<n; i++) {
    mpp[arr[i]]++;
  }


  int q; cin>>q;
  while(q--) {
   int number;cin>>number;
   
   // Fetch
   cout<<mpp[number]<<nline;
  }
  return 0;

}
