#include <bits/stdc++.h>
using namespace std;

/*

------------------------------------------------------------------------------------------------------------------------
You are the one that is responsible for who you are!                                                                   +
6-Months of FOCUS & HARDWORK can put you 5-YEARS ahead in life. Don't Underestimate the power of CONSISTENCY & DESIRE  +
------------------------------------------------------------------------------------------------------------------------

  Syntax ->  bitset < size > varName
  ---------
         
  About bitset,
    - Stores only 1 or 0
    - Use in Segment tree
    - return 1(True) or 0(False)

  Functions,
  (1) All: 
    - All the bits are set it returns True else false
    - If any of the one bit are unset it will return false

  (2) Any:
    - If any of the one bit is set, It will return true else false

  (3) Count:
    - It will print the number of set bits (Set bit means 1)

  (4) Flip:
    - One becomes 0 (1 -> 0), and (0 -> 1) on that particular indexes

  (5) None:
    - If none is set then True else false

  (6) Set:
    - It gets entirely ones 
    - If you give the position sets the index
     Ex: bt.set(2, 0) 
        (index, 1 0r 0)

  (7) Reset:
    - Exact opposite of Set
    - This will turn all indexes to Zero
     Ex: bt.reset()  -> Turn all the indexes to 0
         bt.reset(2) -> Turn the 2nd index to 0

  (8) Size:
    - If you want to get the size of your bit

  (9) Test:
    - You wanna find if a particular index is Set or not
     Ex: bt.set(1) -> Check if the bit is set or not at index 1
------------------------------------------------------------------------------------------------------------------------
*/


int main() {

    bitset<5>bt;  
    cin >> bt;

    cout <<   "All -> " << bt.all()   << "\n";    // Ex: 11111 - True, 10101 - False
    cout <<   "Any -> " << bt.any()   << "\n";    // Ex: 10000 - True, 00000 - False
    cout << "Count -> " << bt.count() << "\n";    // Ex: 10100 - 2  
    cout <<  "Flip -> " << bt.flip()  << "\n";    // Ex: 10100, becomes 10000 bt.flip(2)
    cout <<  "None -> " << bt.none()  << "\n";    // Ex: 10000 - false, 00000 - True
    cout <<   "Set -> " << bt.set()   << "\n";    // Ex: Mention above
    cout << "Reset -> " << bt.reset() << "\n";    // Ex: Mention above
    cout <<  "Size -> " << bt.size()  << "\n";    // Ex: 10101 - 5
    cout <<  "Test -> " << bt.test(2)  << "\n";   // Ex: Mention above

    return 0;
}
