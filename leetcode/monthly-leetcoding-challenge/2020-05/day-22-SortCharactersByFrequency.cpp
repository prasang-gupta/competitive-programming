/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

class Solution {
public:
    string frequencySort(string s) {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        
        map <char, int> m;
        for (int i = 0; i < s.size(); ++i){
            m[s[i]]++;
        }
        
        vector <pair <char,int>> v;
        copy(m.begin(), m.end(), back_inserter <vector <pair <char,int>>> (v));
        sort(v.begin(), v.end(), [](const pair <char, int>& l, const pair <char, int> & r){
                return l.second > r.second;
             });
        
        string ans = "";
        for (auto it = v.begin(); it != v.end(); ++it){
            for (int i = 0; i < it->second; ++i){
                ans += it->first;
            }
        }
        return ans;
    }
};