/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

class Solution {
public:
    vector <int> letter_dist(string s){
        vector <int> dist(26,0);
        for (int i = 0; i < s.size(); ++i){
            dist[s[i]-'a'] += 1;
        }
        return dist;
    }
    
    vector<int> findAnagrams(string s, string p) {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

        vector <int> pdist = letter_dist(p);
        int psize = p.size();
        vector <int> result;
        for (int i = 0; i + psize <= s.size(); ++i){
            if (letter_dist(s.substr(i, psize)) == pdist){
                result.push_back(i);
            }
        }
        return result;
    }
};