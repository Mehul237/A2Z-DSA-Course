
## Construct a BST from a preorder traversal

## 3 approaches

### Approach-01:
- Manually configure the element position
- Start from the first element as a root because it is a pre-order traversal
- Compare the second element where to go on left or right, Same apply for remaining
- 1. Everything in left is lesser than the root,
  2. Everything in right is greater than the root

![Screenshot 2024-06-13 103714](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/335f2687-a940-4a6f-a05e-5e20bf6cac5a)

### Approach-02:
- O(NlogN): for sorting (In-order)
- O(N): For creating a BST
- O(N): For store the in-order element

![Screenshot 2024-06-13 104450](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/31c117f9-cec0-48bc-9a07-ecaf80e46fbc)

![Screenshot 2024-06-13 104548](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/b04e2bde-c6b0-4cd0-9a67-fb1ab063dfee)

![Screenshot 2024-06-13 104817](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/d10a5d01-1d83-46a8-bd86-e81c0aa142cc)


### Approach-03:
- Using lies b/w the range logic

![Screenshot 2024-06-13 104840](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/ac1d5035-d867-4d9e-8c9b-302de724c7df)

![Screenshot 2024-06-13 105939](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/03d2bea5-458c-43f4-90af-f6994c5fdaa5)

![Screenshot 2024-06-13 110119](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/b15554d8-cf7b-4a65-9ca9-8ef4dcf9b8dd)

<img width="960" alt="Screenshot 2024-06-13 112439" src="https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/d0749b91-c6b6-4cca-9157-5685d20b0903">

