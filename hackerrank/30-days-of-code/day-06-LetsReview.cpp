int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    string s;

    cin >> t;
    while(t--){
        cin >> s;
        string odd = "", even = "";
        for (int i = 0; i < s.size(); ++i){
            if (i % 2 == 0){
                even += s[i];
            }
            else{
                odd += s[i];
            }
        }
        cout << even << " " << odd << endl;
    }
    return 0;
}