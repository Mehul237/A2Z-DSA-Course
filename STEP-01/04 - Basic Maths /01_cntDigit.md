
## 01 - Count Digit

### Here are the step-by-step explanations for finding the digit count:

 --------------------------------------------------------------------
 ###  ```Step-01:``` Initialize Counter 
  > int cnt = 0;
  > Start with a counter initialized to zero. This variable will be used to keep track of the number of digits.

###  ```Step-02:``` While Loop for Digit Extraction
  > while(n > 0) { <br>
  >   Enter a loop that continues as long as n is greater than zero <br>
  >  } <br>

###  ```Step-03:``` Extract Last Digit
  > int lastDigit = n % 10;
  > Extract the last digit of the number n using the modulo operator %
  > This operation gets the remainder when n is divided by 10, effectively isolating the last digit

###  ```Step-04:``` Increment Counter
> cnt += 1;
> Increment the counter to keep track of the digit count

###  ```Step-05:``` Remove Last Digit
 > n = n / 10;
 > Remove the last digit from the number n by integer division (dividing by 10)

###  ```Step-06:``` Continue Loop
 > The while loop continues until n becomes zero, and the process repeats for each digit in the original number

###  ```Step-07:``` Return Digit Count
 > return cnt;
 > Once the while loop exits, the function returns the final count of digits.
 > The overall process involves repeatedly extracting the last digit of the number, incrementing the counter, and removing that digit from the number until there are no more digits left
 >  (i.e., the number becomes zero). The final count represents the total number of digits in the original number n.
 --------------------------------------------------------------------


### Implementation,

```cpp

int countDigits(int n) {

	int cnt = 0;

	while(n > 0) {
		int lastDigit = n % 10;
		cnt += 1;
		n = n / 10;
	}	
	return cnt;
}

```


### using maths formula,

``` cpp
int count(int N) {
    int cnt = (int) log10(N) + 1;
    return cnt;
}
```
