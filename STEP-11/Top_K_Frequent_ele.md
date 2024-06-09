<hr>

![Screenshot 2024-06-09 234356](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/ae971e03-6088-4f62-b63f-806820af1e96)

<hr>
<br>

### Approach-01:
- Take extra space (vector to store the key value pair)
- Also sort the vector to get the Top K frequent element

![Screenshot 2024-06-09 234849](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/124d601e-dd0e-43f9-8796-516868fbb24c)

![Screenshot 2024-06-09 235121](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/c16a8881-84e6-4b2b-85ef-ce7e08d86a87)

<hr>
<br>

## Approach-02:

<hr>

![Screenshot 2024-06-09 235623](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/2f8fc60c-f8de-4175-adea-976c49a9f1cc)


<hr>
<br>

```cpp

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> counts;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

        for (auto i : nums) {
            counts[i]++;
        }

        for (auto& i : counts) {
            min_heap.push({i.second, i.first});
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        vector<int> res;
        while (k--) {
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return res;
    }
};

// TC: O(N logK)
// SC: O(K)

```

<hr>
