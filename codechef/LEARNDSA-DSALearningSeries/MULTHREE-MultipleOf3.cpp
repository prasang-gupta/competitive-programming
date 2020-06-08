#include <bits/stdc++.h>

using namespace std;

string mult (long long l, long long a, long long b) {
    if (l == 2){
        return ((a + b) % 3 == 0) ? "YES" : "NO";
    }
    if (l == 3){
        return ((a + b + ((a + b) % 10)) % 3 == 0) ? "YES" : "NO";
    }

    long long digsum = (a + b + ((a + b) % 10));
    digsum += (((2 * (a + b)) % 10) + ((4 * (a + b)) % 10) + ((8 * (a + b)) % 10) + ((6 * (a + b)) % 10)) * ((l - 3) / 4);

    if ((l - 3) % 4 == 1)
        digsum += ((2 * (a + b)) % 10);
    else if ((l - 3) % 4 == 2)
        digsum += ((2 * (a + b)) % 10) + ((4 * (a + b)) % 10);
    else if ((l - 3) % 4 == 3)
        digsum += ((2 * (a + b)) % 10) + ((4 * (a + b)) % 10) + ((8 * (a + b)) % 10);

    return (digsum % 3 == 0) ? "YES" : "NO";
}

int main() {
    long long t, k, d0, d1;
    cin >> t;
    while (t--){
        cin >> k >> d0 >> d1;
        cout << mult(k, d0, d1) << endl;
    }
    return 0;
}