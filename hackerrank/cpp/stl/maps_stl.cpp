int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int q, type, x;
    string s;
    map <string, int> m;
    cin >> q;
    while (q--){
        cin >> type;
        if (type == 1){
            cin >> s >> x;
            m[s] += x;
        }
        else if (type == 2){
            cin >> s;
            m.erase(s);
        }
        else{
            cin >> s;
            auto it = m.find(s);
            if (it != m.end()){
                cout << it->second << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
    }
    return 0;
}