## In-order traversal (Left, Root, Right)

<hr>

![Screenshot 2024-06-11 141718](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/610384b6-dfbc-4ce6-8f7a-11f3482b6e8c)


### **Traverse Left Subtree**: 
- Recursively traverse the left subtree by invoking the preorder function on the left child of the current node
- This step continues the exploration of nodes in a depth first manner

### **Base Case**: 
- If the current node is null, it means we have reached the end of a subtree and there are no further nodes to explore
- Hence the recursive function stops and we return from that particular recursive call

### **Traverse Right Subtree**: 
- After traversing the entire left subtree,we traverse the right subtree recursively
- We once again invoke the preorder function, but this time on the right child of the current node
  
<hr>
<br>

## Visual through understand this,

## Algo:

**Step 1**: Check for base case that if the current node is null, return the void function
![1](https://static.takeuforward.org/content/Inorder-binarytree-image6-esWBb7Ks)

**Step 2**: Invoke the inorder function on the left child to traverse the entire left subtree first
![2](https://static.takeuforward.org/content/Inorder-binarytree-image7-_I3QwQ_R)

**Step 3**: Push the value of the current node into the preorder traversal array
![image](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/c272ee53-ae5b-4dba-9826-68cfbf8f8f04)


**Step 4**: After visiting the current node, we invoke the inorder function on the right child to traverse the right subtree in the end
![](https://static.takeuforward.org/content/Inorder-binarytree-image9-81NLp8CB)




<hr>
<br>

### Code:

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


// Function to perform inorder traversal of the tree and store values in 'arr'
void inorder(Node* root, vector<int>& arr) {

    // If the current node is NULL (base case for recursion), return
    if (root == nullptr) {
        return;
    }

    // Recursively traverse the left subtree
    inorder(root->left, arr);
    
    // Push the current node's value into the vector
    arr.push_back(root->data);

    // Recursively traverse the right subtree
    inorder(root->right, arr);
}


// Function to initiate inorder traversal and return the resulting vector
vector<int> inOrder(Node* root) {

    // Create an empty vector to store inorder traversal values
    vector<int> arr;

    // Call the inorder traversal function
    inorder(root, arr);

    // Return the resulting vector containing inorder traversal values
    return arr;
}



int main() {

    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting inorder traversal
    vector<int> result = inOrder(root);

    // Displaying the inorder traversal result
    cout << "Inorder Traversal: ";

    // Output each value in the inorder traversal result
    for (int val : result) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}

// TC O(N) 
// - where N is the number of nodes in the BT as each node of the BT is visited exactly once

// SC: O(N) 
// - where N is the number of nodes in the BT
// - This is because the recursive stack uses an auxiliary space 
//   which can potentially hold all nodes in the tree when dealing 
//   with a skewed tree (all nodes have only one child), 
//   consuming space proportional to the number of nodes
// - In the average case or for a balanced tree, the maximum number of 
//   nodes that could be in the stack at any given time would be 
//   roughly the height of the tree hence O(log2N)
```


```cpp

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void inorder(Node* root, vector<int>& arr) {

    if (root == nullptr) {
        return;
    }

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

vector<int> inOrder(Node* root) {
    vector<int> arr;
    inorder(root, arr);

    return arr;
}


int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = inOrder(root);
    cout << "Inorder Traversal: ";

    for (int val : result) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}

```
