
## Q1: Find min and max value in BST

<hr>

![Screenshot 2024-06-13 102134](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/b04ecc67-ccf1-48a7-9100-dd20c19f81c5)

![Screenshot 2024-06-13 102158](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/1907f601-5e50-4e4a-b415-b7f343382fe2)

![Screenshot 2024-06-13 102235](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/378a71bd-1c35-4020-b6ff-f7bf50e0e2be)

![Screenshot 2024-06-13 102246](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/2ca578a1-3b4b-4966-9e9e-c38f36f77d90)

![Screenshot 2024-06-13 102258](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/1bbea0b4-9d24-479a-8634-96734870fe35)

<hr>
<br>

## Follow-up question:

### Find in-order successor and precedecessor  
- [Naukri.com - article](https://www.naukri.com/code360/library/finding-inorder-predecessor-of-a-node-in-a-binary-search-tree)
- [GFG - article](https://www.geeksforgeeks.org/inorder-predecessor-successor-given-key-bst/)
- [Tutorialhorizon](https://tutorialhorizon.com/algorithms/inorder-predecessor-and-successor-in-binary-search-tree/)

![tutorialhorizon](https://tutorialhorizon.com/static/media/algorithms/2014/12/Inorder-Predecessor-and-Successor-in-Binary-Search-Tree.jpg)

<hr>
<br>

Condition,
- If KeyValue is smaller than Root,
  1. Go to left subtree (Predecessor)
  2. Otherwise go to right subtree (Successor)

Statement,
- Predecessor of Node FindX will be
  Right most element , (in the left subtree -- Condition)
  
- Successor of Node FindX will be
  Left most element, (in the right subtree -- Condition)


```cpp


// Successor : FindX >= rootValue

// --> Successor of Node FindX will be
// **-- Left most element
// **-- in the right subtree

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {

        TreeNode* Successor = NULL;

        while (root != NULL) {

            // Subtree
            if (p->val >= root->val ) {    
                root = root->right;
            }
            
            // element
            else {
                Successor = root;
                root = root->left;
            }
        }
        return Successor;
    }
};

```

<hr>
<br>

```cpp


// Predecessor : rootValue >= FindX  

// --> Predecessor of Node FindX will be
// **-- Right most element
// **-- in the left subtree


class Solution {
public:
    TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) {

        TreeNode* predecessor = NULL;

        while (root != NULL) {

            // Subtree
            if (root->val >= p->val) {    
                root = root->left;
            }

            // element
            else {
                predecessor = root;
                root = root->right;
            }
        }
        return predecessor;
    }
};

```

<hr>
