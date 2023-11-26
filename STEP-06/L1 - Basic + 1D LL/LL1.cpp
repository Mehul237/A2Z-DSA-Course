#include <bits/stdc++.h>
using namespace std;

// class we preffered instead of struct 

class Node {
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};


Node* convertArr2LL(vector<int> &arr) {

    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1; i<arr.size(); i++) {

        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}


int lengthOfLL(Node* head) {
    int cnt = 0;
    Node* temp = head;

    while(temp) {
        temp = temp -> next;
        cnt++;
    }
    return cnt;
}


int checkIfPresent(Node* head, int val) {
    Node* temp = head;
    while(temp) {
        if(temp -> data == val) return 1;
        temp = temp -> next;
    }
    return 0;
}



int main() {

    vector<int> arr = {7, 9, 37, 69};

    // Q1. 
    Node* head = convertArr2LL(arr);
    cout << "Convert arr to LL: " << head -> data << "\n";





/*
-------- Traversal to print value -------
    Node* temp = head;                  
    while(temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
-----------------------------------------
*/






   // Q2. 
   cout << "Length of LL: "<<lengthOfLL(head) <<"\n";


   // Q3. 0-Not, 1-Present
   cout << "Check if present: "<< checkIfPresent(head, 237);








/*
-------------------------------------------------------------------------------------------------
 Implementation:
 
    Node* y = new Node(arr[0], nullptr);  //1. If, we remove star then don't work
    cout << y;  // Directly gives you the memory like a ptr to the memory location
    cout << y -> data;

----------------------------------------
Alternate: print the value of head node
----------------------------------------

    Node y = Node(arr[0], nullptr);  //2. Slightly changes in the code and print the Head value
    cout << y.data;
    cout << y.next;   // print 0, Bcz we don't provide the next link info.

------------------------------------------------------------------------------------------------
*/

    return 0;

}
