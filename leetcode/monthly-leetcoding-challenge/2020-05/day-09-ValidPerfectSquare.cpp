/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Follow up: Do not use any built-in library function such as sqrt.

 

Example 1:

Input: num = 16
Output: true
Example 2:

Input: num = 14
Output: false
 

Constraints:

1 <= num <= 2^31 - 1
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

        if (num == 1){
            return true;
        }
        for (int i = 2; i <= num/2; ++i){
            if (i == 46341){
                return false;
            }
            if (i*i == num){
                return true;
            }
        }
        return false;
    }
};