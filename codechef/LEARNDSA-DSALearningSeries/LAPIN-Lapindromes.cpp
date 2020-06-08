#include <bits/stdc++.h>

using namespace std;

vector <int> letter_dist(string s){
    vector <int> dist(26,0);
    for (int i = 0; i < s.size(); ++i){
        dist[s[i]-'a'] += 1;
    }
    return dist;
}

string islapin(string s) {
    vector <int> first = letter_dist(s.substr(0, s.size()/2)), second;
    if (s.size() % 2 == 0){
        second = letter_dist(s.substr(s.size()/2, s.size()/2));
    }
    else{
        second = letter_dist(s.substr(s.size()/2 + 1, s.size()/2));
    }

    if (first == second){
        return "YES";
    }
    return "NO";
}

int main() {
    int t;
    string s;
    cin >> t;
    while(t--){
        cin >> s;
        cout << islapin(s) << endl;
    }
    return 0;
}