/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

You may assume that both strings contain only lowercase letters.
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
    
    bool canConstruct(string ransomNote, string magazine) {
        vector <int> rd, md;
        rd = letter_dist(ransomNote);
        md = letter_dist(magazine);
        
        for (int i = 0; i < 26; ++i){
            if (rd[i] > md[i]){
                return false;
            }
        }
        
        return true;
    }
};