/*
------------------------------------------------------------------------------------------------------------------------
You are the one that is responsible for who you are!                                                                   +
6-Months of FOCUS & HARDWORK can put you 5-YEARS ahead in life. Don't Underestimate the power of CONSISTENCY & DESIRE  +
------------------------------------------------------------------------------------------------------------------------

***********************
 Mehul Thuletiya      *
 CF: Mehul_Thuletiya  *
 CC: mehul237         *
***********************

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nline "\n"


void swap1(int a, int b) {
  a = a + b;
  b = a - b;
  a = a - b;
  cout << a <<' '<< b << '\n';
}

void swap2(int a, int b) {
  int temp = a;
  a = b;
  b = temp;
  cout << a <<' '<< b << '\n';
}

void swap3(int a, int b) {
  int x = a ^ b;
  int i = 0;
    
  while(x) {
    int curr = 1<<i;
    
    // if that bit in x is 1, then that bit is different in a and b
    if(x & curr ) {

      // change that bit in a
      a = a ^ curr;
      // change that bit in b
      b = b ^ curr;
      // make that 1 bit to 0 in x
      x = x ^ curr;
    }
    i++;
  }
  cout << a <<' '<< b << '\n';
}



void bubble_sort(int arr[], int N) {
  for (int i=N-1; i >= 0; i--) {
    for (int j=0; j <= i-1; j++) {

      if (arr[j] > arr[j + 1]) {
        swap(arr[j+1], arr[j]);
      }

    }
  }
}


int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  // Size
  int N; 
  cin >> N;

  // Array created N size of arrray
  int arr[N];

  // Taking input
  for(int i=0; i<N; i++) {
    cin >> arr[i];

    bubble_sort(arr, N);
  }

  // Printing the array, After the selection sort Implement
  for(int i=0; i<N; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}
