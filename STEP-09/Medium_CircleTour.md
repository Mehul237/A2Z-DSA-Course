
[Circle Tour -- 2 Pointer, Sliding window, Queue](https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1)


```cpp

class Solution {
public:

    // Function to find starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between
    int tour(petrolPump p[], int n) {
        int deficit = 0;
        int balance = 0;
        int start = 0;

        for (int i = 0; i < n; i++) {
            balance += p[i].petrol - p[i].distance;
            if (balance < 0) {
                start = i + 1;
                deficit += balance;
                balance = 0;
            }
        }

        if (balance + deficit >= 0) {
            return start;
        } else {
            return -1;
        }
    }
};
