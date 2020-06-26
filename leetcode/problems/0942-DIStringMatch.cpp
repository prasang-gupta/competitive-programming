/*
Given a string S that only contains "I" (increase) or "D" (decrease), let N = S.length.

Return any permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:

If S[i] == "I", then A[i] < A[i+1]
If S[i] == "D", then A[i] > A[i+1]
 

Example 1:

Input: "IDID"
Output: [0,4,1,3,2]
Example 2:

Input: "III"
Output: [0,1,2,3]
Example 3:

Input: "DDI"
Output: [3,2,0,1]
 

Note:

1 <= S.length <= 10000
S only contains characters "I" or "D".
*/

class Solution {
public:
    Solution () {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    }
    
    vector<int> diStringMatch(string S) {
        int n = S.size();
        vector <int> ans (n+1);
        int inc = 0, dec = n;
        
        for (int i = 0; i < n; ++i){
            if (S[i] == 'I'){
                ans[i] = inc++;
            }
            else{
                ans[i] = dec--;
            }
        }
        ans[n] = inc;
        return ans;
    }
};