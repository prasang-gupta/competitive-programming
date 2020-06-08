int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    map <string, string> m;
    string name, number;
    int n;
    cin >> n;
    while(n--){
        cin >> name >> number;
        m[name] = number;
    }

    while(cin >> name){
        auto it = m.find(name);
        if (it == m.end()){
            cout << "Not found\n";
        }
        else{
            cout << name << "=" << it->second << endl;
        }
    }
    return 0;
}