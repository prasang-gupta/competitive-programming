/*
A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

Also, a self-dividing number is not allowed to contain the digit zero.

Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.

Example 1:
Input: 
left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
Note:

The boundaries of each input argument are 1 <= left <= right <= 10000.
*/

class Solution {
public:
    Solution () {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    }
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector <int> ans;
        int n;
        for (int i = left; i <= right; ++i){
            n = i;
            while (n){
                if (n%10 == 0 || i % (n%10) != 0){
                    break;
                }
                n /= 10;
            }
            if (n){
                continue;
            }
            ans.push_back(i);
        }
        return ans;
    }
};