#include <bits/stdc++.h>

using namespace std;

void reverse (int n) {
    int firstzero = 1;
    while(n){
        if (firstzero && n % 10 == 0){
            n /= 10;
            continue;
        }
        firstzero = 0;
        cout << n%10;
        n /= 10;
    }
    cout << endl;
}

int main() {
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        reverse(n);
    }
    return 0;
}