## Pre-order traversal (Root, Left, Right)

<hr>

![image](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/6fef60d0-8bf7-406d-8990-bc13b60cc14b)

### **Base Case**: 
- If the current node is null, it means we have reached the end of a subtree and there are no further nodes to explore
- Hence the recursive function stops and we return from that particular recursive call

### **Traverse Left Subtree**: 
- Recursively traverse the left subtree by invoking the preorder function on the left child of the current node
- This step continues the exploration of nodes in a depth first manner

### **Traverse Right Subtree**: 
- After traversing the entire left subtree,we traverse the right subtree recursively
- We once again invoke the preorder function, but this time on the right child of the current node
  
<hr>
<br>

## Visual through understand this,

## Algo:

**Step 1**: Check for base case that if the current node is null, exit the void function
![1](https://static.takeuforward.org/content/preorder-binarytree-image7-DWwCi3rf)

**Step 2**: Push the value of the current node into the preorder traversal array
![2](https://static.takeuforward.org/content/preorder-binarytree-image8-WZuB4oql)

**Step 3**: Invoke the preorder function on the left child then right child to traverse the left and right subtrees in the preorder manner respectively
![3](https://static.takeuforward.org/content/preorder-binarytree-image9-FInfa4h3)

**Entire step overview**
![](https://static.takeuforward.org/content/preorder-binarytree-image5-C75VJARA)

**Final output:**
![output](https://static.takeuforward.org/content/preorder-binarytree-image6-z5NdJrra)


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


void preorder(Node* root, vector<int>& arr) {

    // If the current node is NULL (base case for recursion), return
    if (root == nullptr) {
        return;
    }

    // Push the current node's value into the vector
    arr.push_back(root->data);

    // Recursively traverse the left subtree
    preorder(root->left, arr);

    // Recursively traverse the right subtree
    preorder(root->right, arr);
}


// Function to initiate preorder traversal and return the resulting vector
vector<int> preOrder(Node* root) {

    // Create an empty vector to store preorder traversal values
    vector<int> arr;

    // Call the preorder traversal function
    preorder(root, arr);

    // Return the resulting vector containing preorder traversal values
    return arr;
}


int main() {

    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting preorder traversal
    vector<int> result = preOrder(root);

    // Displaying the preorder traversal result
    cout << "Preorder Traversal: ";

    // Output each value in the preorder traversal result
    for (int val : result) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}

// TC: O(N)
// - where N is the number of nodes in the binary tree as each node of the binary tree is visited exactly once

// SC: O(N)
// - where N is the number of nodes in the binary tree as an additional space for array is
//   allocated to store the values of all ‘N’ nodes of the binary tree
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


void preorder(Node* root, vector<int>& arr) {

    // If the current node is NULL (base case for recursion), return
    if (root == nullptr) {
        return;
    }

    arr.push_back(root->data);

    preorder(root->left, arr);
    preorder(root->right, arr);
}


vector<int> preOrder(Node* root) {
    vector<int> arr;
    preorder(root, arr);

    return arr;
}


int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = preOrder(root);
    cout << "Preorder Traversal: ";

    for (int val : result) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}

```
