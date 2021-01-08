class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        string a="", b = "";
        for (auto const& w : word1){
            a += w;
        }
        for (auto const& w : word2){
            b += w;
        }
        return a == b;
    }
};
