/*
Given an integer n, return any array containing n unique integers such that they add up to 0.

 

Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
Example 2:

Input: n = 3
Output: [-1,0,1]
Example 3:

Input: n = 1
Output: [0]
 

Constraints:

1 <= n <= 1000
*/

class Solution {
public:
    Solution () {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    }
    
    vector<int> sumZero(int n) {
        int dig = n/2;
        vector <int> ans(n);
        for (int i = 0; i < dig; ++i){
            ans[i*2] = i+1;
            ans[i*2 + 1] = -(i+1);
        }
        if (n % 2){
            ans[n-1] = 0;
        }
        return ans;
    }
};