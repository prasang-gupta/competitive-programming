#include <bits/stdc++.h>

using namespace std;

int coinflip (int i, int n, int q) {
    if (n % 2 == 0){
        return n / 2;
    }
    if (i == q) {
        return n / 2;
    }
    return (n/2) + 1;
}

int main() {
    int t, g, n, i, q;
    cin >> t;
    while (t--){
        cin >> g;
        for (int idx = 0; idx < g; ++idx){
            cin >> i >> n >> q;
            cout << coinflip(i, n, q) << endl;
        }
    }
    return 0;
}