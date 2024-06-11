
## Morris In order traversal in BT
- It is a traversal algo aiming to achieve SC O(1) without recursion or an external DS like stack
- It uses the concept of Threaded BT (Threading to traverse the tree efficiently

### **Key idea**:
- Is to establish a temporary link b/w the current node and its in-order successor

## Observation:
<hr>

![1](https://static.takeuforward.org/content/morris-inorder-image5-SYCxFVO2)

- The inorder predecessor of a node is the rightmost node in the left subtree
- ** So when we traverse the left subtree, We encounter a node whose **right child is null**,
  this is the **last node in that subtree**

![2](https://static.takeuforward.org/content/morris-inorder-image6-hNbvQ5zp)

<hr>
<br>

## When we are currently at a node, the following cases can arise:

<hr>

**Case-1**: The current node has no left subtree
- Print the value of the current node
- Then to the right child of the current node

![3](https://static.takeuforward.org/content/morris-inorder-image7-ovl_DGGd)

<hr>
<br>

**Case-2**: There is a left subtree, and the right-most child of this left subtree is pointing to null
- Set the right-most child of the left subtree to point to the current node
- Move to the left child of the current node

![4](https://static.takeuforward.org/content/morris-inorder-image8-XM_CCGkj)

<hr>
<br>

**Case-3**: There is a left subtree, and the right-most child of this left subtree is already pointing to the current node
- Print the value of the current node
- Revert the temporary link (set it back to null)
- Move to the right child of the current node

![5](https://static.takeuforward.org/content/morris-inorder-image9-UDEjgRPj)


<hr>
<br>


## Steps to implement,

**Step-01**: 
- Initialise a current to traverse the tree
- Set current to the root of the BT

**Step-02**: While the current is not null: 
- If the current node has no left child, print the current node's value and move to the right child
- ie. set the current to its right child

![6](https://static.takeuforward.org/content/morris-inorder-image10-qB8MYLzF)

**Step-03**: 
- If the current node has a left child, we find the in-order predecessor of the current node
- This in-order predecessor is the rightmost node in the left subtree or the left subtree's rightmost node.

** If the right child of the in-order predecessor is null:
- Set the right child to the current node
- Move to the left child (i.e., set current to its left child)

** If the right child of the in-order predecessor is not null:
- Revert the changes made in the previous step by setting the right child as null
- Print the current node's value
- Move to the right child (i.e., set current to its right child)

Repeat steps 2 and 3 until the end of the tree is reached.

![](https://static.takeuforward.org/content/morris-inorder-image11-FF2x8Lmx)



```cpp


#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
public:

    vector<int> getInorder(TreeNode* root) {

        vector<int> inorder;

        // 1. Pointer to the current node, starting from the root
        TreeNode* cur = root;

        // 2. Loop until the current node is not NULL
        while (cur != NULL) {

            // Case-01: If the current node's left child is NULL
            if (cur->left == NULL) {

                // Add the value of the current node to the inorder vector
                inorder.push_back(cur->val);

                // Move to the right child
                cur = cur->right;
            } else {

                // Case-02:
                // If the left child is not NULL,
                // find the predecessor (rightmost node in the left subtree)

                TreeNode* prev = cur->left;

                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }

                // If the predecessor's right child is NULL, 
                // establish a temporary link and move to the left child
                if (prev->right == NULL) {
                    prev->right = cur;
                    cur = cur->left;
                } else {

                    // If the predecessor's right child is already linked, 
                    // remove the link, add current node to inorder vector,
                    // and move to the right child
                    prev->right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }

        // Return the inordertraversal result
        return inorder;
    }
};



```


- **Time Complexity:**
  - Morris Traversal visits each node at most twice.
  - Each node is visited once for establishing the temporary link and once for reverting it.
  - Time complexity is linear, O(2N), where N is the number of nodes in the Binary Tree.

- **Space Complexity:**
  - Morris Traversal is an in-place algorithm.
  - It doesn't use additional data structures like stacks or recursion.
  - Only a constant amount of extra space is utilized.
  - Space complexity is O(1), constant irrespective of the input size.
