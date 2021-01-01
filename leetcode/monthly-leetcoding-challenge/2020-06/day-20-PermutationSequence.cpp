/*
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        --k;
        int lastfac = 1, curdigit, lastn = n;
        string ans = "";
        vector <int> digits (n);
        for (int i = 0; i < n; ++i){
            digits[i] = i+1;
            lastfac *= digits[i];
        }
        
        lastfac /= lastn--;
        while (k && digits.size()){
            curdigit = k / lastfac;
            k = k % lastfac;
            lastfac /= lastn--;
            
            ans += digits[curdigit] + '0';
            auto it = digits.begin() + curdigit;
            digits.erase(it);
        }
        
        for (int i = 0; i < digits.size(); ++i){
            ans += digits[i] + '0';
        }
        
        return ans;
    }
};