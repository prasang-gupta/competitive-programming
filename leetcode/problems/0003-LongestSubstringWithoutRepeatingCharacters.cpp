/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
    Solution () {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    }

    int lengthOfLongestSubstring(string s) {
        map <int, int> m;
        int startidx = 0, maxcount = 0;

        for (int i = 0; i < s.size(); ++i){
            auto elem = m.find(s[i]);
            if (elem == m.end()){
                m[s[i]] = i;
                if (maxcount < i-startidx+1){
                    maxcount = i-startidx+1;
                }
            }
            else{
                if (startidx < elem->second + 1){
                    startidx = elem->second + 1;
                }
                m[elem->first] = i;
                if (maxcount < i-startidx+1){
                    maxcount = i-startidx+1;
                }
            }
        }
        return maxcount;
    }
};