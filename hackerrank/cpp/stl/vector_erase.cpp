int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, x, j, k;
    cin >> n;

    vector <int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }

    cin >> x;
    a.erase(a.begin()+x-1);

    cin >> j >> k;
    a.erase(a.begin()+j-1, a.begin()+k-1);

    cout << a.size() << endl;
    for (int i = 0; i < a.size(); ++i){
        cout << a[i] << " ";
    }
    return 0;
}