int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q, tempsize, curval;
    cin >> n >> q;
    
    vector <vector <int>> a(n);
    for (int i = 0; i < n; ++i){
        cin >> tempsize;
        vector <int> temp(tempsize);
        for (int j = 0; j < tempsize; ++j){
            cin >> temp[j];
        }
        a[i] = temp;
        temp.clear();
    }

    int i, j;
    while(q--){
        cin >> i >> j;
        cout << a[i][j] << endl;
    }

    return 0;
}