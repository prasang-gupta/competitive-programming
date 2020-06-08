int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, q;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }

    cin >> q;
    while (q--){
        cin >> n;
        auto idx = lower_bound(a.begin(), a.end(), n);
        if (*idx == n){
            cout << "Yes " << (idx - a.begin()) + 1 << endl;
        }
        else{
            cout << "No " << (idx - a.begin()) + 1 << endl;
        }
    }
    return 0;
}