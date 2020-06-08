/*
Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true 
Explanation: 20 = 1
Example 2:

Input: 16
Output: true
Explanation: 24 = 16
Example 3:

Input: 218
Output: false
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        if (!n)
            return false;
        while (n % 2 == 0){
            n /= 2;
        }
        if (n == 1)
            return true;
        return false;
    }
};