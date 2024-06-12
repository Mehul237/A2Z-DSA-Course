
[Search in BST](https://takeuforward.org/data-structure/search-in-a-binary-search-tree-2/)

<br>

### Algo:

<hr>

**Step-01**:
- Start at the root of the BST
![1](https://static.takeuforward.org/content/search-in-bst-image5-7Pt1rqR8)


**Step-02**:
1. While the current node is not null and the current node’s value is not equal to the key recursively travel the tree by:
- If the target value is less than the current node’s value,
  move to the left child as smaller values are on the left subtree in the BST
- If the target value is greater than the current node’s value,
  move to the right child as larger values are on the right subtree in the BST

![2](https://static.takeuforward.org/content/search-in-bst-image6-ORREpe-X)


**Step-03**:
- Return the current node if it contains the target value, or NULL if the value is not found in the BST

![3](https://static.takeuforward.org/content/search-in-bst-image7-pcjNE2m5)

<br>
<hr>

```cpp

class Solution {
public:

    TreeNode* searchBST(TreeNode* root, int val) {

        // Loop until either the tree is
        // exhausted (NULL) or the value is found
        while(root != NULL && root->val != val) {

            // Check if the target value is
            // less than the current node's value.
            // If so, move to the left subtree
            // (values smaller than the current node).
            // Otherwise, move to the right subtree
            // (values larger than the current node).

            root = val < root->val ? root->left : root->right;
        }

        // Return the node containing the target value, if found;
        // otherwise, return NULL.
        return root;
    }
};

```

<hr>


**Time Complexity**: O(log2N) 
- Where N is the number of nodes in the BST
- In the best case scenario, where the tree is balanced, the time complexity is the height of the tree i.e., log2N.
- In the worst-case scenario, where the tree is degenerate (linear), the time complexity becomes O(n),
  as it would require traversing all nodes along the path from the root to the leaf.

**Space Complexity**: O(1) 
- since the algorithm does not use any additional space or data structures.
- The algorithm does use auxiliary stack space from recursion.
- In the average and worst-case scenarios, the space complexity for recursive stack space is O(h)
