#include <bits/stdc++.h>

using namespace std;

int minshot (string s, int n) {
    int suma = 0, sumb = 0, rema = n, remb = n;
    for (int i = 0; i < 2*n; i++){
        if (i % 2 == 0){
            suma += s[i] - '0';
            rema--;
        }
        else{
            sumb += s[i] - '0';
            remb--;
        }
        if (suma - sumb > remb || sumb - suma > rema){
            return i+1;
        }
    }
    return 2 * n;
}

int main() {
    int t, n;
    string s;
    cin >> t;
    while (t--){
        cin >> n >> s;
        cout << minshot(s, n) << endl;
    }
    return 0;
}