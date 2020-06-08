#include <bits/stdc++.h>

using namespace std;

long long maxrevenue (vector <long long> &a) {
    sort(a.begin(), a.end());

    long long maxsum = 0, asize = a.size();
    for (long long i = 0; i < asize; ++i){
        if (maxsum < a[i]*(asize-i)){
            maxsum = a[i]*(asize-i);
        }
    }
    return maxsum;
}

int main() {
    long long n;
    cin >> n;
    
    vector <long long> a(n);
    for (long long i = 0; i < n; ++i){
        cin >> a[i];
    }

    cout << maxrevenue(a) << endl;
    return 0;
}