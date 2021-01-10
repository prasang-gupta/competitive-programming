/*
Given a positive integer num, output its complement number. The complement strategy is to flip the bits of its binary representation.

 

Example 1:

Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:

Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 

Constraints:

The given integer num is guaranteed to fit within the range of a 32-bit signed integer.
num >= 1
You could assume no leading zero bit in the integer’s binary representation.
This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/
*/

class Solution {
public:
    Solution () {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    }

    int findComplement(int num) {
        string a = bitset<32>(num).to_string();
        int leadingzero = 1;
        for (int i = 0; i < a.size(); ++i){
            if (leadingzero && a[i] == '0'){
                continue;
            }
            if (leadingzero && a[i] == '1'){
                leadingzero = 0;
                a[i] = '0';
                continue;
            }
            a[i] = (a[i] == '0') ? '1' : '0';
        }
        return bitset<32>(a).to_ulong();
    }
};