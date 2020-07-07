/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
*/

class Solution {
public:
    Solution () {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    }
    
    int hammingDistance(int x, int y) {
        string xs = bitset<32>(x).to_string();
        string ys = bitset<32>(y).to_string();
        
        int count = 0;
        for (int i = 0; i < 32; ++i){
            count += (xs[i]-'0') ^ (ys[i]-'0');
        }
        return count;
    }
};