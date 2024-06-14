```cpp

#include <bits/stdc++.h>
using namespace std;

void reverseSentence1(string str) {
    string word = "";
    stack<string> st;

    for(int i=0; i<str.size(); i++) {
        if(str[i] != ' ') {
            word += str[i];
        } else {
            st.push(word);
            word = "";
        }
    }
    st.push(word);

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    } cout << "\n";
}



int main() {

    // Q1. Reverse a sentence
    string str = "Hey, What are you doing";
    reverseSentence(str);

    return 0;
}

```
