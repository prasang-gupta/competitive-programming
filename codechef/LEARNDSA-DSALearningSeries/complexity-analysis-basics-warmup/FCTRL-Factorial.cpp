#include <bits/stdc++.h>

using namespace std;

long long faczero (long long a) {
    long long sum = 0;
    for (int i = 1; i < 13; ++i){
        sum += a / pow(5, i);
    }
    return sum;
}

int main() {
    int t;
    long long n;
    cin >> t;
    while (t--){
        cin >> n;
        cout << faczero(n) << endl;
    }
    return 0;
}