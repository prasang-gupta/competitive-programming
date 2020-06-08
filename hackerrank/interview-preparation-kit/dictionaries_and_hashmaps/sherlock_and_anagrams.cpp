// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    map <vector <int>, int> m;
    for (int i = 0; i < s.size(); ++i){
        vector <int> freq(26, 0);
        for (int j = i; j < s.size(); ++j){
            freq[s[j]-'a']++;
            m[freq]++;
        }
    }

    int ans = 0;
    for (auto it = m.begin(); it != m.end(); ++it){
        ans += ((it->second-1)*it->second)/2;
    }
    return ans;
}