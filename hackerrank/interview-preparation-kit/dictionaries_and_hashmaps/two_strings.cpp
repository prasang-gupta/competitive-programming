vector <int> letter_dist(string s){
    vector <int> dist(26,0);
    for (int i = 0; i < s.size(); ++i){
        dist[s[i]-'a'] += 1;
    }
    return dist;
}

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    vector <int> a = letter_dist(s1), b = letter_dist(s2);
    for (int i = 0; i < 26; ++i){
        if (a[i] && b[i]){
            return "YES";
        }
    }
    return "NO";
}