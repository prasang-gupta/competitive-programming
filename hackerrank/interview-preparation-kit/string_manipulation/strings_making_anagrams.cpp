vector <int> letter_dist(string s){
    vector <int> dist(26,0);
    for (int i = 0; i < s.size(); ++i){
        dist[s[i]-'a'] += 1;
    }
    return dist;
}

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    vector <int> x,y;
    x = letter_dist(a);
    y = letter_dist(b);

    int sum = 0;
    for (int i = 0; i < x.size(); ++i){
        sum += abs(x[i]-y[i]);
    }
    return sum;
}