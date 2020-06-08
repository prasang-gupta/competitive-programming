int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int q, type, x;
    set <int> s;
    cin >> q;
    while(q--){
        cin >> type >> x;
        switch(type){
            case 1: s.insert(x); break;
            case 2: s.erase(x); break;
            case 3: cout << ((s.find(x) == s.end()) ? "No" : "Yes") << endl;
        }
    }  
    return 0;
}