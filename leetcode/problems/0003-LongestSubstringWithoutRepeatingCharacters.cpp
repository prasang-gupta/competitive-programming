/*
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

class Solution {
public:
    Solution () {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    }
    
    int lengthOfLongestSubstring(string s) {
        int no_of_chars = 256, ans = 0, start = 0;
        vector <int> last(no_of_chars, -1);
        
        for (int i = 0; i < s.size(); ++i){
            start = max(start, last[s[i]]+1);
            ans = max(ans, i-start+1);
            last[s[i]] = i;
        }
        return ans;
    }
};
