#include <bits/stdc++.h>

using namespace std;

int maxspeed (vector <int> &a) {
    int ans = 1, minval = a[0];
    for (int i = 1; i < a.size(); ++i){
        if (minval > a[i]){
            minval = a[i];
            ans++;
        }
    }
    return ans;
}

int main() {
    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        vector <int> speeds(n);
        for (int i = 0; i < n; ++i){
            cin >> speeds[i];
        }
        cout << maxspeed(speeds) << endl;
    }
    return 0;
}