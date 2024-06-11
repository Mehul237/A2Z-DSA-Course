[Iterative pre-order traversal](https://youtu.be/Bfqd8BsPVuw?feature=shared)

<hr>

![](https://static.takeuforward.org/content/preorder-binarytree-image7-LoL_nauS)

<hr>


```cpp

class Solution {
public:

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;

        // If the root is null, return an empty traversal result
        if (root == nullptr) {
            return preorder;
        }

        // Create a stack to store nodes during traversal
        stack<TreeNode*> st;

        // Push the root node onto the stack
        st.push(root);

        // Perform iterative preorder traversal
        while (!st.empty()) {

            // Get the current node from the top of the stack
            root = st.top();

            // Remove the node from the stack
            st.pop();

            // Add the node's value to the preorder traversal result
            preorder.push_back(root->val);

            // Push the right child onto the stack if exists
            if (root->right != nullptr) {
                st.push(root->right);
            }

            // Push the left child onto the stack if exists
            if (root->left != nullptr) {
                st.push(root->left);
            }
        }

        // Return the preorder traversal result
        return preorder;
    }
}

```


<hr>

## Time Complexity:

- **Traversal Operation:** Every node of the binary tree is visited exactly once in the traversal process.
   
- **Constant Time Operations:** For each node, the operations performed (pushing and popping from the stack, accessing node values, etc.) are constant time operations.

- **Overall Time Complexity:** Since every node is visited once and constant time operations are performed for each node, the overall time complexity is O(N), where N is the number of nodes in the binary tree.

## Space Complexity:

- **Stack Space:** The stack can potentially hold all nodes in the tree when dealing with a skewed tree (all nodes have only one child), consuming space proportional to the number of nodes.

- **Overall Space Complexity:** Considering the stack space usage, the overall space complexity is O(N), where N is the number of nodes in the binary tree.

<hr>
