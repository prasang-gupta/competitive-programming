#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n, val;
    string s, origin;
    cin >> t;
    while (t--){
        int sum = 0;
        cin >> n >> origin;
        for (int idx = 0; idx < n; ++idx){
            cin >> s;
            if (s == "CONTEST_WON"){
                cin >> val;
                sum += (val > 20) ? 300 : 300 + (20 - val);
            }
            else if (s == "TOP_CONTRIBUTOR"){
                sum += 300;
            }
            else if (s == "BUG_FOUND"){
                cin >> val;
                sum += val;
            }
            else{
                sum += 50;
            }
        }
        if (origin == "INDIAN"){
            cout << sum / 200 << endl;
        }
        else{
            cout << sum / 400 << endl;
        }
    }
    return 0;
}