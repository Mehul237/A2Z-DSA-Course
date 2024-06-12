
## K-th largest and smallest element in BST

![Screenshot 2024-06-12 223529](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/2ff3a71f-0488-4f11-bbf5-e23406237af2)

![Screenshot 2024-06-12 223738](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/6f1edbdb-5612-47fb-9dbc-7594a3ce3afc)

![Screenshot 2024-06-12 223958](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/2e2b738a-9d3a-44ea-a5db-849b10ed7d9e)

![Screenshot 2024-06-12 224150](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/028195e2-9d11-43e2-bb73-3adf3f709892)

![Screenshot 2024-06-12 224234](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/1d997066-4a45-42ed-8198-0b84faca748a)

<hr>

```cpp

// Using Morris Inorder Traversal 
// TC: O(N)
// SC: O(1)

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans;
        TreeNode* curr = root;

        while (curr) {
            if (curr->left == NULL) {
                count++;
                if (count == k) {
                    ans = curr->val;
                }

                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;

                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    count++;
                    prev->right = NULL;
                    if (count == k) {
                        ans = curr->val;
                    }
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};

```

<hr>
<br>

## Kth-largest element
- For Kth largest it should be (n-k+1)th smallest
- Just a small observation
- In the kth largest we can do a reverse in-order kind of thing: RIGHT ROOT LEFT with the counter logic
- if we take reverse inorder than the elements are sorted in descending fashion,
  so we can directly get kth largest element

![Screenshot 2024-06-12 225309](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/f677bc8e-842a-4b70-9693-3d31ffc1c08e)

![Screenshot 2024-06-12 225621](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/3115ce2a-d69b-44d7-a5b7-09b32e374825)

