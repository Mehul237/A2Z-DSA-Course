
[Ceil in BST](https://docs.google.com/document/d/1v59v-dtdoO_5MkH1u4mdW2Gjdqpf8r7JZS27AfM4hyk/edit?usp=sharing)
- From the root choose where to go (left or right),  find ceil: rootValue >= key
- If (key > root value) then go to right
- If (key < root value) then, go to left   – According to question update ceil

<hr>

![Screenshot 2024-06-12 154203](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/a22371fb-f135-44dc-9abd-bc0386602c25)

![Screenshot 2024-06-12 154258](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/e0831497-256d-40d4-b12d-b738013b200e)

<hr>

```cpp

#include <bits/stdc++.h> 


int findCeil(BinaryTreeNode<int> *root, int key) {
    
    int ceil = -1; 

    while(root != NULL) {

        if(root->data == key) {
            ceil = root->data;
            return ceil;
        }

        if(key > root->data) {
            root = root->right;
        } else {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}

// TC: O(logN)
// SC: O(logN)
```

<hr>

![Screenshot 2024-06-12 160634](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/e5c382c9-f0c0-4562-9fb0-d140ea210aa3)

<hr>
