
## Dry - run
<hr>

![Screenshot 2024-06-11 110505](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/eceaca9e-4ef5-4e3c-9efc-27b2a8199977)
![Screenshot 2024-06-11 110553](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/dfcacea4-1195-4b5b-890e-155f723e4aed)

<hr>

## Implementation through visual

### 1. Node structure
![structure](https://static.takeuforward.org/content/Screenshot%202024-01-07%20at%205.50.42%20PM-bFh4meWZ)

### 2. Node Constructor
![Constructure](https://static.takeuforward.org/content/Screenshot%202024-01-07%20at%205.56.55%20PM-4gvUnL61)

### 3. Node connection
![Connection](https://static.takeuforward.org/content/Screenshot%202024-01-07%20at%206.29.40%20PM-vI6I2bJk)

```cpp

#include <iostream>

// Structure definition for a node in a binary tree
struct Node {

    // Defining the value of the node (integer data)
    int data;

    // Reference pointer to the left child node
    Node* left;

    // Reference pointer to the right child node
    Node* right;

    // Method to initialize the node with a value
    Node(int val) {

        // Set the value of the node to the passed integer
        data = val;

        // Initialize left and right pointers as NULL
        left = right = NULL;
    }
};


int main() {

    // Creating a new node for the root of the
    // binary tree using dynamic allocation
    Node* root = new Node(1);

    // Creating left and right child
    // nodes for the root node
    root->left = new Node(2);
    root->right = new Node(3);
    
    // Creating a right child node for
    // the left child node of the root
    root->left->right = new Node(5);
}

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
        left = right = NULL;
    }
};


int main() {

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(5);

    return 0;
}

```

### Output:

![](https://static.takeuforward.org/content/Screenshot%202024-01-07%20at%206.37.26%20PM-YmDylwMS)
