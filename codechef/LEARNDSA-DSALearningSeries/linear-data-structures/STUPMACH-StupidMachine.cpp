#include <bits/stdc++.h>

using namespace std;

long long maxtokens (vector <long long> &a) {
    long long curmin = a[0], sum = 0;
    for (int i = 0; i < a.size(); ++i){
        if (a[i] < curmin){
            curmin = a[i];
        }
        sum += curmin;
    }
    return sum;
}

int main() {
    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        vector <long long> a(n);
        for (int i = 0; i < n; ++i){
            cin >> a[i];
        }
        cout << maxtokens(a) << endl;
    }
    return 0;
}