/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/

class Solution {
public:
    Solution () {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    }
    
    int numSquares(int n) {
        vector <int> squares;
        for (int i = 1; ; ++i){
            if (i*i <= n){
                squares.push_back(i*i);
            }
            else{
                break;
            }
        }
        
        vector <int> dp (n+1, 0);
        for (int i = 1; i < n+1; ++i){
            int minval = INT_MAX;
            for (int j = 0; j < squares.size(); ++j){
                if (i - squares[j] < 0){
                    break;
                }
                if (minval > dp[i-squares[j]] + 1){
                    minval = dp[i-squares[j]] + 1;
                }
            }
            dp[i] = minval;
        }
        return dp[n];
    }
};