#include <bits/stdc++.h>

using namespace std;

int maxvalid (string s) {
    int maxlen = 0, opencount = 0;
    for (int i = 0; i < s.size(); ++i){
        if (s[i] == '<'){
            ++opencount;
        }
        else{
            --opencount;
        }
        if (opencount < 0){
            return maxlen;
        }
        if (!opencount)
            maxlen = i + 1;
    }
    return maxlen;
}

int main() {
    int t;
    string s;
    cin >> t;
    while (t--){
        cin >> s;
        cout << maxvalid(s) << endl;
    }
    return 0;
}