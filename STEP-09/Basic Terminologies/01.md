[Includehelp - article](https://www.includehelp.com/data-structure-tutorial/stack-using-c-and-cpp-data-structure-tutorial.aspx)


![Image Description](https://drive.google.com/uc?id=1iZES8eKcPYdwIYKRw5ohNYETNkmWkDRN)
![Image Description](https://drive.google.com/uc?id=1uGDNYckc_CnO3imXsSdVJMVOv6GOi8n7)
![Image Description](https://drive.google.com/uc?id=1DWn8MbVH5fO7iuZ3_o-qW6tx7mds3lxJ)

<hr>
<br>

```cpp

#include <bits/stdc++.h>
using namespace std;
 
int main() {

    stack<string> s;
 
    s.push("A");    // Insert `A` into the stack
    s.push("B");    // Insert `B` into the stack
    s.push("C");    // Insert `C` into the stack
    s.push("D");    // Insert `D` into the stack
 
    cout << "The stack size is " << s.size() << endl;
    cout << "The top element is " << s.top() << endl;   // s.peek()
 
    s.pop();        // removing the top element (`D`)
    s.pop();        // removing the next top (`C`)
 
    cout << "The stack size is " << s.size() << endl;
 
    // check if the stack is empty
    if (s.empty()) {
        cout << "The stack is empty\n";
    }
    else {
        cout << "The stack is not empty\n";
    }


    return 0;
}

```


<hr>
<br>

## Q1: Implement stack using array
 
```cpp

#include <bits/stdc++.h>
using namespace std;

class Stack {

// properties
public:
    int* arr;
    int top;
    int size;

    // behaviour
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element) {
        if (size - top > 1) {
            top++;
            arr[top] = element;
        } else {
            cout << "Stack OverFlow" << endl;
        }
    }

    void pop() {
        if (top >= 0) {
            top--;
        } else {
            cout << "Stack UnderFlow" << endl;
        }
    }

    int peek() {
        if (top >= 0)
            return arr[top];
        else {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        if (top == -1) {
            return true;
        } else {
            return false;
        }
    }
};


int main() {

    Stack st(5);

    st.push(22);
    st.push(43);
    st.push(44);
    st.push(22);
    st.push(43);
    st.push(44);

    cout << st.peek() << "\n";
    st.pop();
    cout << st.peek() << "\n";
    st.pop();
    cout << st.peek() << "\n";
    st.pop();
    cout << st.peek() << "\n";

    if (st.isEmpty() ) {
        cout << "Stack is Empty mere dost " << "\n";
    } else {
        cout << "Stack is not Empty mere dost " << "\n";
    }

    /*
    // creation of stack
    stack<int> s;

    // push operation
    s.push(2);
    s.push(3);

    // pop
    s.pop();

    cout << "Printing top element " << s.top() << endl;

    if(s.empty() ) {
        cout << "Stack is empty " << endl;
    }
    else {
        cout << "stack is not empty " << endl;
    }

    cout << "size of stack is " << s.size() << endl;

    */

    return 0;
}

```


<hr>
<br>

## Q2: Implement Two stacks in array

![Screenshot 2024-05-30 232740](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/c8f6d4ba-d620-4ec9-a790-5d894644f9e6)
![Screenshot 2024-05-30 232754](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/46c62074-953b-45cc-90c8-a2d1d0bc1c7e)


```cpp
class TwoStack {
    int* arr;
    int top1;
    int top2;
    int size;

public:
    // Initialize TwoStack
    TwoStack(int s) {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    // Push in stack 1.
    void push1(int num) {
        // atleast a empty space present
        if (top2 - top1 > 1) {
            top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if (top2 - top1 > 1) {
            top2--;
            arr[top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if (top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        } else {
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if (top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        } else {
            return -1;
        }
    }
};

```
