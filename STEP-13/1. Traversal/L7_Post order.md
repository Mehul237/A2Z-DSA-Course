## Post-order traversal (Left, Right, Root)

<hr>

![image](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/dc6a3041-bcf8-4b5b-977b-a84d61891641)

## Recursive fn:

**Traverse Left Subtree**: 
- Explore the left subtree by recursively invoking the postorder fn on the left child of the current node,
- ensuring a depth-first approach to node exploration

**Traverse Right Subtree**: 
- After fully traversing the left subtree, we move on to the right subtree,
- invoking the postorder function on the right child of the current node

**Process Current Node**: 
- After exploring the children of the current node,
- We process it by adding its value to the postorder traversal array
  
<hr>
<br>

## Visual through understand this,

## Algo:

**Step 1**: 

**Step 2**:

**Step 3**: 

**Entire step overview**


**Final output:**



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


void postorder(Node* root, vector<int>& arr) {

    // Base case: if root is null, return
    if (root == NULL) {
        return;
    }

    // Traverse left subtree
    postorder(root->left, arr);

    // Traverse right subtree
    postorder(root->right, arr);

    // Visit the node (append node's data to the array)
    arr.push_back(root->data);
}


vector<int> postOrder(Node* root) {

    vector<int> arr;
    postorder(root, arr);

    return arr;
}

void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << "\n";
}


int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    l vector<int> result = postOrder(root);

    cout << "Postorder traversal: ";
    printVector(result);

    return 0;
}

// TC: O(N)
// - where N is the number of nodes in the BT as each node of the BT is visited
//   exactly once

// SC: O(N)
// - where N is the number of nodes in the BT as an additional space for array
//   is allocated to
//   store the values of all ‘N’ nodes of the BT

```
