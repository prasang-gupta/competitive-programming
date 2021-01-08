class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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
