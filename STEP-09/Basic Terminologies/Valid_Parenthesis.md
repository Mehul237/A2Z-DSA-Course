## Valid Parenthesis

![Screenshot 2024-05-31 082133](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/cd949d3b-e854-4df6-90ba-df08369e5aed)


### Approach:
![Screenshot 2024-05-31 083540](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/03e3874a-8ed6-44a1-979b-8c48c6f968a6)
![Screenshot 2024-05-31 083547](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/f9f085a2-38ff-4cc4-a41c-69013df2fb89)
![Screenshot 2024-05-31 083555](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/485308a2-9c67-472d-b733-66e1c6e1e2a1)
![Screenshot 2024-05-31 083605](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/103bdf28-e340-4acc-9e31-2a51b03ebb69)
![Screenshot 2024-05-31 083622](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/0be00f9a-158e-498c-8d6f-3fc590a2e1a1)



```cpp

// TC: O(N)
// SC: O(N)

bool isValidParenthesis(string expression) {
    stack<char> s;

    for (int i=0; i<expression.length(); i++) {
        char ch = expression[i];

        // 1. if opening bracket, stack push
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }  else {

            // 2. if close bracket, stacktop check and pop
            if (!s.empty()) {

                char top = s.top();
                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')) {
                    s.pop();
                } else {
                    return false;
                }
            } 
            // Stakc is empty
            else {
                return false;
            }
        }
    }

    if (s.empty())
        return true;
    else
        return false;
}

```
