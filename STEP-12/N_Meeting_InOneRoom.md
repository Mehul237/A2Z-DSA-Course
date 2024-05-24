
### Question: [N meeting In one room](https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1)

### Dry-run:
![Image](https://drive.google.com/uc?id=1QxON6aFKXf4fQgTZ542CEVi4Sh2doB6t)

```cpp

// TC: O(N) + O(N logN) + O(N) =~ O(N logN)
// SC: O(1)

class Solution {
public:

    static bool cmp(pair<int, int> a, pair<int, int> b) {
        return b.second > a.second;
        
        //  {1, 2}, {3, 4}
        // --> 2 < 3 : return a.second < b.second
        // --> 3 > 2 : return b.second > a.second
    }
    
    
    int maxMeetings(int start[], int end[], int n) {
        
        // Step-01: Create pair for each meeting time
        vector<pair<int, int>> meetings;

        for (int i=0; i<n; i++) {
            pair<int, int> p = make_pair(start[i], end[i]);
            meetings.push_back(p);
        }

        // Step-02: Sort ans according to end time
        sort(meetings.begin(), meetings.end(), cmp);

       // Step-03: Iterate on the pair and check condition and increase the cnt of maxMeetings
        int maxMeetings = 1;
        int endTime = meetings[0].second;

        for (int i=1; i<n; i++) {
            if (meetings[i].first > endTime) {
                maxMeetings++;
                endTime = meetings[i].second;
            }
        }
        return maxMeetings;
    }
};

```

<hr>

## Follow - up question: [Maximum Meetings in One Room](https://www.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1)

```cpp


class Solution {
public:

    // Comparator function to compare meetings based on their end times 
    static bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
        if (a.second.second != b.second.second) {      // If end times are different
            return a.second.second < b.second.second;  // Sort by end times
        }
        return a.second.first < b.second.first;        // If end times are equal, sort by start times
    }


    // Function to find the maximum number of non-overlapping meetings
    vector<int> maxMeetings(int N, vector<int>& S, vector<int>& F) {

        // Step 01: Create pair for each meeting time
        vector<pair<int, pair<int, int>>> meetings;   // (meeting index, (start time, end time))
        vector<int> ans;                              // Vector to store indices of selected meetings

        for (int i = 0; i < N; i++) {
            pair<int, int> p = make_pair(S[i], F[i]);  // Create pair for each meeting
            meetings.push_back({i + 1, p});            // Meeting index starts from 1, add to meetings vector
        }

        // Step 02: Sort meetings according to end time (and start time if end times are equal)
        sort(meetings.begin(), meetings.end(), cmp);

        // Step 03: Iterate on the sorted meetings and select non-overlapping meetings
        int endTime = meetings[0].second.second;     // End time of the first meeting
        ans.push_back(meetings[0].first);            // Add the index of the first meeting

        for (int i = 1; i < N; i++) {
            if (meetings[i].second.first > endTime) {   // If the current meeting doesn't overlap with previous
                ans.push_back(meetings[i].first);       // Add the index of the current meeting
                endTime = meetings[i].second.second;    // Update the end time
            }
        }

        sort(ans.begin(), ans.end());                  // Sort the indices of selected meetings
        return ans;                                    // Return the indices of non-overlapping meetings
    }
};

```
