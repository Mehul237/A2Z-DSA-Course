#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string str = "Mehul "; 
    string s = "Thuletiya"; 
   // getline(cin, str);

// 01 - Size
    cout << "Size -> " << str.size() << "\n";
    cout << "Size -> " << str.length() << "\n";

// 02 - find
    cout << "Find or not (0-Not, 1-Present) -> " << str.find('e') << "\n";

// 03 - substr
    cout << "Return substring from that index to end -> " << str.substr(1) << "\n";

// 04 - at
    cout << "Return present at that index -> " << str.at(0) << "\n";

// 05 - append
    cout << "Pushes the defined parameter to the end of the string -> " << str.append(s) << "\n";

// 06 - compare
    cout << s.compare(str) ? cout <<"doesn't match\n" : cout <<"Matches\n";

// 07 - clear
    s.clear();
    cout << "Clear s string -> " << s << "\n";

// 08 - front
    cout << "Front -> " << str.front() << "\n";

// 09 - back
    cout << "Back -> " << str.back();   // s - No ele, str - Mehul Thuletiya

   return 0;

}