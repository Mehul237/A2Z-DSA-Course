
[Merge 2 heaps](https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1)
- Using heapify algorithm
- Using 1 based indexing
- Merge logic (Two different thing push into one)

```cpp

class Solution {
public:

    void heapify(vector<int>& arr, int size, int index) {

        // Follow 1-based indexing
        int largestParent = index;
        int leftChild = 2 * index + 1;
        int rightChild = (2 * index) + 2;

        // 1. Parent ndoe Compare from its child node (left & right)
        if (leftChild < size && arr[largestParent] < arr[leftChild]) {
            largestParent = leftChild;
        }

        if (rightChild < size && arr[largestParent] < arr[rightChild]) {
            largestParent = rightChild;
        }

        // 2. Take to its correct position
        if (largestParent != index) {
            swap(arr[largestParent], arr[index]);
            heapify(arr, size, largestParent); // Find in more depth to reach to
                                               // its correct pos
        }
    }


    vector<int> mergeHeaps(vector<int>& a, vector<int>& b, int n, int m) {

        // Step-01: Merge both arrays into one
        vector<int> ans;

        for (auto i : a)
            ans.push_back(i);

        for (auto i : b)
            ans.push_back(i);

        // Step-02: Build heap using merged array
        int size = ans.size();

        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(ans, size, i);
        }
        return ans;
    }
};

```
