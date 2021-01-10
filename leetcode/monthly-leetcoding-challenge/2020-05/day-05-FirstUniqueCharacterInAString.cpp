/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

class Solution {
public:
    Solution () {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    }

    int firstUniqChar(string s) {
        vector <int> letters(26,0);
        for (int i = 0; i < s.size(); ++i){
            letters[s[i]-'a'] += 1;
        }
        for (int i = 0; i < s.size(); ++i){
            if (letters[s[i]-'a'] == 1){
                return i;
            }
        }
        return -1;
    }
};