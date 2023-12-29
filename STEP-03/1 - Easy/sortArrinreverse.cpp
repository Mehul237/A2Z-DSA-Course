#include <bits/stdc++.h>
using namespace std;

int main() {
  
    // Example array
    int arr[] = {5, 2, 9, 1, 5, 6};

    // Calculate the size of the array
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    // Sorting the array in reverse order
    sort(arr, arr + arrSize, greater<int>());
     // After sorting you need to do is reverse the sorting element
     // reverse(arr, arr + arrSize);

    // Printing the sorted array
    cout << "Sorted array in reverse order: ";
    for (int i = 0; i < arrSize; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
