
## [Lemonade change -- Implementation based](https://leetcode.com/problems/lemonade-change/)

![01](https://drive.google.com/uc?id=1gwg2NAn2afPKpNsMbrW2S035G3PPhjTD)
![02](https://drive.google.com/uc?id=1hEOv3UssaXT5wRP97EMtKSSC_Ohy9b6y)
![03](https://drive.google.com/uc?id=1idM1CZ2VQvxeUZH8VWyt09bVydKWPi_N)
![04](https://drive.google.com/uc?id=1BZKl4oee4LiTYIhyo8_MagY3bfQdsL4s)


```cpp
// TC: O(N)
// SC: O(1)

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int fives = 0, tens = 0;

        for (int bill : bills) {
            if (bill == 5) {                    // Case-01: 05
                fives++;
            } else if (bill == 10) {            // Case-02: 10
                if (fives == 0) {
                    return false;
                }
                fives--;
                tens++;
            } else {
                if (tens > 0 && fives > 0) {    // Case-03: 20
                    tens--;
                    fives--;
                } else if (fives >= 3) {
                    fives -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

```
