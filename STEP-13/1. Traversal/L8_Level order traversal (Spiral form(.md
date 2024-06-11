
## [Level order traversal in spiral form](https://takeuforward.org/data-structure/level-order-traversal-of-a-binary-tree/)

![](https://static.takeuforward.org/content/level-order-image7-RtoPWzLj)

```cpp

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val; 
    TreeNode* left; 
    TreeNode* right;

    // Default constructor for TreeNode
        TreeNode() {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    // Constructor with a value parameter
    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }

    // Constructor with value, left child, and right child parameters
    TreeNode(int x, TreeNode* l, TreeNode* r) {
        val = x;
        left = l;
        right = r;
    }
};


class Solution {
public:

    // Function to perform level-order traversal of a BT
    vector<vector<int>> levelOrder(TreeNode* root) {

        // 1. 2D vector to store the level order traversal
        vector<vector<int>> ans; 
        if (root == nullptr) {

            // If the tree is empty, return an empty vector
            return ans; 
        }
        
        // 2. Create a queue to store nodes for level-order traversal
        queue<TreeNode*> q; 

        // Push the root node to the queue
        q.push(root); 

        while (!q.empty()) {

            // 3. Get the size of the current level
            int size = q.size(); 

            // 4. Create a vector to store nodes at the current level
            vector<int> level; 

            for (int i = 0; i < size; i++) {

                // Get the front node in the queue
                TreeNode* node = q.front(); 

                // Remove the front node from the queue
                q.pop(); 

                // Store the node value in the current level vector
                level.push_back(node->val); 

                // Enqueue the child nodes if they exist
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            // Store the current level in the answer vector
            ans.push_back(level); 
        }

        // Return the level-order traversal of the tree
        return ans; 
    }
};


void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}


int main() {


    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Create an instance of the Solution class
    Solution solution; 

    // Perform level-order traversal
    vector<vector<int>> result = solution.levelOrder(root); 

    cout << "Level Order Traversal of Tree: "<< endl;

    // Printing the level order traversal result
    for (const vector<int>& level : result) {
        printVector(level);
    }

    return 0;
}

```


## Time Complexity:

1. **Traversal Operation:** Each node of the binary tree is traversed exactly once in a level-order traversal.
   
2. **Constant Time Operations:** Processing each node involves constant time operations like enqueueing, dequeuing, and appending to the result vector.

3. **Overall Time Complexity:** Since each node is processed once and constant time operations are performed on each node, the overall time complexity is O(N), where N is the number of nodes in the binary tree.

## Space Complexity:

1. **Queue Space:** In the worst-case scenario, the queue needs to hold all the nodes of the last level of the binary tree. Since the last level could have at most N/2 nodes (in a complete binary tree), the space complexity of the queue is proportional to O(N).

2. **Result Vector Space:** The resultant vector stores the values of the nodes level by level, containing all the nodes of the tree. Hence, it also contributes to O(N) space complexity.

3. **Overall Space Complexity:** Considering both the space used by the queue and the result vector, the overall space complexity is O(N), where N is the number of nodes in the binary tree.
