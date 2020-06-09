#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n, s, p, v;
    cin >> t;
    while (t--){
        int maxprofit = 0;
        cin >> n;
        for (int i = 0; i < n; ++i){
            cin >> s >> p >> v;
            if (maxprofit < ((int)(p / (s + 1))) * v){
                maxprofit = ((int)(p / (s + 1))) * v;
            }
        }
        cout << maxprofit << endl;
    }
    return 0;
}