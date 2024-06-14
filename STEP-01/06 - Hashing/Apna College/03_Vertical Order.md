## Q2: Vertical Order Print

<hr>

![Screenshot 2024-06-14 145847](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/b2c60e16-b9f2-4291-aa0e-27d7ba4c0e84)

![Screenshot 2024-06-14 150034](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/879e838e-2b0c-4c4d-996f-94e5f7c01855)

![Screenshot 2024-06-14 150052](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/410f6c49-4252-4771-9727-27611b6a972b)

![Screenshot 2024-06-14 150156](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/0436e2b2-2c80-4059-8816-d6d435d7c83d)


> ## Note:
> 1. The code uses a map to store the node keys, which has an average time complexity of O(log n) for search, insert, and delete operations
>    This makes the code efficient for large binary trees
> 2. The code uses a recursive function to traverse the binary tree,
>    which can cause a stack overflow for very deep trees
> 3. An iterative approach using a queue can be used to avoid this issue

<hr>

```cpp

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define vi vector<int>
#define pii pair<int, int>
#define ff first
#define ss second
#define vii vector<pii>
#define rep(i, a, b) for(int i=a; i<b; i++)
#define setBits(x) builtin_popcount(x)

#define nline "\n"
const int MOD = 1e9 + 7;



struct Node
{
    int key;
    Node *left, *right;
};

Node* newNode(int key) {
    Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}


void getVerticalOrder(Node* root, int hdis, map<int, vi> &m) {

    if(root == NULL) {
        return;
    }

    // add the node key to the map at the current horizontal distance
    m[hdis].push_back(root->key);

    // recursively traverse the left and right subtrees
    getVerticalOrder(root->left, hdis-1, m);
    getVerticalOrder(root->right, hdis+1, m);
}


int main() {
    
    // 1. Creating BT
    Node *root = newNode(10);
    root->left = newNode(7);
    root->right = newNode(4);
    root->left->left = newNode(3);
    root->left->right = newNode(11);
    root->right->left = newNode(14);
    root->right->right = newNode(6);

   // 2. Create a map to store the vertical order
   map<int, vector<int>> m;
   int hdis = 0;

   getVerticalOrder(root, hdis, m);

   map<int, vi> ::iterator it;
   for(it = m.begin(); it != m.end(); it++) {
    for(int i=0; i<(it->second.size()); i++) {
        cout << (it->second)[i] << " ";
    }
    cout << "\n";
   }
    

    return 0;
}
```

<hr>
<br>
