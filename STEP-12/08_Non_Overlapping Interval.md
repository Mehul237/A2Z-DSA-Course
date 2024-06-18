
```cpp

class Solution {
public:

    static bool comp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        int totalSize = intervals.size();
        int lastendTime = intervals[0][1];
        int cnt = 1;                                    // Start with the first interval counted

        for(int i=1; i<totalSize; i++) {
            if(intervals[i][0] >= lastendTime) {
                cnt++;
                lastendTime = intervals[i][1];
            }
        }
        return totalSize - cnt;
    }
};

```
