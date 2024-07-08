/*
 258. Add Digits
Easy
Topics
Companies
Hint
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

 

Example 1:

Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.
Example 2:

Input: num = 0
Output: 0
 

Constraints:

0 <= num <= 231 - 1
 

Follow up: Could you do it without any loop/recursion in O(1) runtime?
*/

//Code:

class Solution {
public:
    int addDigits(int num) {
        int a,b,c,d;
    int result = 0;
    int fresult = 0;

    a = num % 10;
    b = num / 10; 

    result = a+b;
    
    c = result%10;
    d = result/10;
    
    fresult = c+d;
    return fresult;
        
    }
};
/*
Accepted
Runtime: 3 ms
Case 1
Case 2
Input
num =
38
Output
2
Expected
2
*/
