#include <bits/stdc++.h>

using namespace std;

void maxbrackets (vector <int> &a) {
    int maxdepth = 0, opencount = 0, maxdepthidx = -1, maxsize = 0, maxsizeidx = -1;
    vector <int> brackets;
    for (int i = 0; i < a.size(); ++i){
        if (a[i] == 1){
            ++opencount;
            brackets.push_back(i);
            if (maxdepth < opencount){
                maxdepth = opencount;
                maxdepthidx = i;
            }
        }
        else{
            --opencount;
            if (maxsize < i - brackets.back() + 1){
                maxsize = i - brackets.back() + 1;
                maxsizeidx = brackets.back();
            }
            brackets.pop_back();
        }
    }
    cout << maxdepth << " " << maxdepthidx + 1 << " " << maxsize << " " << maxsizeidx + 1 << endl;
}

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    maxbrackets(a);

    return 0;
}