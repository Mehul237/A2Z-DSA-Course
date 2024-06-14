## Theory,

![Screenshot 2024-06-14 141456](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/fc6c526a-5fa8-4a08-8572-9e9627724f51)

![Screenshot 2024-06-14 141550](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/a6104fd8-2700-40d1-93e5-d42bc9653a25)

![Screenshot 2024-06-14 141628](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/65fe6a5a-4413-42be-8bdd-0500a1954bb4)

![Screenshot 2024-06-14 141807](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/4baf7412-67ba-47f0-898a-853cd04ec744)

![Screenshot 2024-06-14 141847](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/9f40f1f0-e414-45a6-ab31-b7287be75d8d)


<br>
<hr>

![Screenshot 2024-06-14 142005](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/21d184ca-8696-4bad-a239-92c48a41e698)

![Screenshot 2024-06-14 142138](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/f4ccbd91-aeeb-4e18-a974-7864e3fdda86)

![Screenshot 2024-06-14 142210](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/d92748ca-d2bc-436b-ac20-a3558ea39ff4)


> ### Unordered_map
> - <i> Fast-lookup </i> : Constant time complexity for searching, insert and delete operations. For large input sizes and prioritizing speed
> - <i> Better performance for large inputs </i> : Uses hashtable, it can handle large inputs for efficiently
> - <i> Less memory allocation </i> :  typically allocates memory in a contiguous block, which can reduce memory allocation overhead compared to map

> ## Map
> - <i> Slow-lookup </i> : uses a balanced BST, which results in a logarithmic time complexity (O(log n)) for search, insert, and delete operations
> - <i> More memory allocation </i> : map allocates memory for each node in the BST, which can lead to more memory allocation overhead compared to unordered_map.
>  ## Some scenarios where map might be a better choice:
> - <i> Ordered frequency count </i> : If you need to maintain the order of elements while counting their frequencies, map is a better choice since it preserves the order of elements
> - <i> Small input sizes </i> : For small input sizes, the difference in performance between unordered_map and map might be negligible, and map might be a better choice if you need to maintain the order of elements.


<hr>
<br>

## Q1: Count frequency of elements

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



int main() {

    // Q: Count frequency of elements

    // 
    int n;
    cin >> n;

    vi a(n);
    map<int, int> mp;

    rep(i, 0, n) {
        cin >> a[i];
    }

    rep(i, 0, n) {
        mp[a[i]]++;
    }

    for(auto it : mp) {
        cout << it.first << " " << it.second << "\n";
    }


    return 0;
}

```

<hr>
<br>


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


