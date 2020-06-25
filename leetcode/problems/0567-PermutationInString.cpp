/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/

class Solution {
public:
    Solution () {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    }

    vector <int> letter_dist(string s){
        vector <int> dist(26,0);
        for (int i = 0; i < s.size(); ++i){
            dist[s[i]-'a'] += 1;
        }
        return dist;
    }
    
    bool checkInclusion(string s1, string s2) {
        int size = s1.size();
        vector <int> s1dist = letter_dist(s1), subdist = letter_dist(s2.substr(0, size));
        if (subdist == s1dist){
            return true;
        }
        for (int i = 1; i + size <= s2.size(); ++i){
            subdist[s2[i-1]-'a'] -= 1;
            subdist[s2[i+size-1]-'a'] += 1;
            if (subdist == s1dist){
                return true;
            }
        }
        return false;
    }
};