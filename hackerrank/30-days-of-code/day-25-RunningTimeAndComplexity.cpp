int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t, n, ifbreak;
    cin >> t;
    while (t--){
        cin >> n;
        if (n == 1){
            cout << "Not prime\n";
            continue;
        }
        ifbreak = 0;
        for (int i = 2; i <= sqrt(n); ++i){
            if (n % i == 0){
                cout << "Not prime\n";
                ifbreak = 1;
                break;
            }
        }
        if (!ifbreak){
            cout << "Prime\n";
        }
    }
    return 0;
}
