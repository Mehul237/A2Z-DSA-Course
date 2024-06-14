
## 1. Using recursion

Reason to implement,
- If you're working with small to medium-sized stacks, 
  the recursive way might be a good choice due to its concise code and ease of implementation
- the recursive approach requires multiple function call stack frames
- However, the recursive way has a higher space complexity due to the function call stack

Idea to implement,
- The idea of the solution is to hold all values in Function Call Stack until the stack becomes empty (Reverse)
- When the stack becomes empty, insert all held items one by one at the bottom of the stack (insertAtbottom)


Steps to implement,
- Create a stack and push all the elements in it
- Call reverse(), which will pop all the elements from the
  stack and pass the popped element to function insert_at_bottom()
- Whenever insert_at_bottom() is called it will insert the
  passed element at the bottom of the stack
- Print the stack    

<hr>

```cpp

#include <bits/stdc++.h>
using namespace std;


void insertAtbottom(stack<int> &st, int x) {
  // If the stack is empty, push the element x onto the stack
  // This is the base case for the recursion
  if(st.empty()) {
    st.push(x);
    return;
  }

  // Hold the top element of the stack in a variable element
  // This element will be pushed back onto the stack later
  int element = st.top();
  st.pop();

  // Recursively call insertAtbottom with the remaining stack and element x
  // This will continue until the stack is empty
  insertAtbottom(st, x);

  // Push the held element back onto the stack
  // This is done after the recursive call returns
  st.push(element);
}


void reverse(stack<int> &st) {

  // Original: 5 4 3 2 1
  // reverse:  1 2 3 4 5

  // 1. Removes 5 from stack, leaving 4 3 2 1
  // -- reverse(st) is called recursively with remaining stack
  // N. When removes 1, leaving an empty stack
  // -- reverse(st) returns as stack is empty

  if(st.empty()) {
    return;
  }

  // 1. Hold the top element in fn call stack
  // -- until reach end of the stack

  // For one element
  int element = st.top();
  st.pop();   

  // for remaining elements
  reverse(st);  

  // Insert the held element at the bottom
  insertAtbottom(st, element);
}



int main() {


  stack<int> st;

  for(int i=1; i<=5; i++) {
    st.push(i);
  }

  reverse(st);

  while(!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }


  return 0;
}

```


## Time Complexity:
- The TC of the `reverse` function is O(n^2) because each recursive call to `insertAtbottom` takes O(n) time, 
  and there are n recursive calls. This results in a quadratic time complexity

## Space Complexity:
- The SC of the `reverse` function is O(n) because the recursive call stack can grow up to a depth of n,
  where n is the number of elements in the stack. This is because each recursive call adds a new layer to the call stack

<hr>
<br>

## 2. Using another stack

Reason to implement,
- if you're dealing with large stacks or have memory constraints, 
  creating another stack to reverse is a more efficient and safer approach
- the iterative approach (creating another stack) is generally more efficient in terms of memory usage, 
  as it only requires a single extra stack

<hr>

```cpp

#include <bits/stdc++.h>
using namespace std;

int main() {

  stack<int> st;

  for(int i=1; i<=4; i++) {
    st.push(i);
  }

//   cout << "Original stack: ";
//   while(!st.empty()) {
//     cout << st.top() << " ";
//     st.pop();
//   } cout << "\n";

  stack<int> ans;
  
  while(!st.empty()) {
    ans.push(st.top());
    st.pop();
  }


  cout << "Reverse stack: ";
  while(!ans.empty()) {
    cout << ans.top() << " ";
    ans.pop();
  } cout << "\n"; 


  return 0;
}


// TC: O(N)
// -- Push, Reverse (Stored into ans) and print

// SC: O(N)
// -- N: number of elements in stack
// -- Two stack are used: 1 for original and 1 for reverse
```

<hr>
