
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
