
## Brute force approach
- Using left and right array and find max of it and return ans

```cpp

#include<bits/stdc++.h>
using namespace std;

void candy(vector<int>& arr) {
    int n = arr.size();

    vector<int> left(n); 
    left[0] = 1;

    for(int i=1; i<n; i++) {
        if(arr[i] > arr[i - 1]) {
            left[i] = left[i - 1] + 1;
        } else {
            left[i] = 1; 
        }
    }

    cout << "Left Part--> " ;
    for(int i = 0; i < n; i++) {
        cout << left[i] << " "; 
    }
    cout << "\n";


    vector<int> right(n); 
    right[n-1] = 1;

    for(int i=n-2; i>=0; i--) {
        if(arr[i] > arr[i + 1]) {
            right[i] = right[i + 1] + 1;
        } else {
            right[i] = 1; 
        }
    }

    cout << "Right Part--> " ;
    for(int i=0; i<n; i++) {
        cout << right[i] << " "; 
    }
    cout << "\n";

	int sum = 0;
	for(int i=0; i<n; i++) {
		sum += max(left[i], right[i]);
	}
	cout << sum;
}



int main() {
    vector<int> a = {1, 3, 2, 1};
    candy(a);

    return 0;
}

```

## Better approach
- Only help of left array and find the max of it and add into sum
- Elininate the right part to solve problem in efficient manner

```cpp


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> allocation(n, 1);

        for(int i=1; i<n; ++i) {
            if(ratings[i] > ratings[i - 1]) {
                allocation[i] = allocation[i - 1] + 1;
            }
        }

        for(int i=n-2; i>=0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                allocation[i] = max(allocation[i], allocation[i + 1] + 1);
            }
        }
        
        int sum = 0;
        for (int a : allocation) {
            sum = sum + a;
        }
        return sum;
    }
};

```

## Optimal approach
- Slope method







<br>
<br>
<br>


[Shop in Candy Store](https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1)

<hr>

Two scenario,
 1. Mini case: Buy low amount first and take k amount free (High candy price)
 -     -- We want to minimize the price
 2. Maxi case: Buy High amount first and take k amount free (Low candy price)
 -     -- We want to maximize the price
   
![01](https://drive.google.com/uc?export=view&id=15E-e8l9VltvWsQRSHa_fQseQDG6ITaT2)
![02](https://drive.google.com/uc?export=view&id=1v4sunmWBmv9QZHRY5JXFeOJvvUmmSV-g)
![03](https://drive.google.com/uc?export=view&id=1R2Wq0synroCZ5i-Ytcu10b2Ubk2VZpZV)
