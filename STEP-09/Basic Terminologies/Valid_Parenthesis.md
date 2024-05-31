## Valid Parenthesis

![Screenshot 2024-05-31 082133](https://github.com/Mehul237/A2Z-DSA-Course/assets/117193057/cd949d3b-e854-4df6-90ba-df08369e5aed)


```cpp

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
