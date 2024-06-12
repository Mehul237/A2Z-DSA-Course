
[Floor in BST](https://docs.google.com/document/d/1v59v-dtdoO_5MkH1u4mdW2Gjdqpf8r7JZS27AfM4hyk/edit?usp=sharing)
- From the root choose where to go (left or right),  find ceil: rootValue <= key
- If (key > root value) then go to right   – According to question update floor
- If (key < root value) then, go to left 

<hr>

![Screenshot 2024-06-12 162234](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/c37722aa-caa4-4d04-ba46-52ab196f022b)


<hr>

```cpp

#include <bits/stdc++.h> 
// Find: root->data <= key

int floorInBST(TreeNode<int> *root, int key) {
    int floor = -1;

    while(root != NULL) {

        if(root->val == key) {
            floor = root->val;
            return floor;
        }

        if( key > root->val) {
            floor = root->val;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return floor;
}

```
