// Complete the isValid function below.
string isValid(string s) {
    vector <int> a = letter_dist(s);
    int freq = 0, isfirst = 1, mode = -1;

    map <int, int> m;
    for (int i = 0; i < a.size(); ++i){
        if (a[i]){
            m[a[i]]++;
        }
    }

    for (auto it = m.begin(); it != m.end(); ++it){
        cout << it->first << " " << it->second << endl;
        if (mode < it->second){
            freq = it->first;
            mode = it->second;
        }
    }
    
    for (int i = 0; i < a.size(); ++i){
        if (a[i] && a[i] != freq){
            if (a[i] == 1){
                if (isfirst){
                    isfirst = 0;
                    continue;
                }
                else{
                    return "NO";
                }
            }
            if (abs(a[i]-freq) > 1){
                cout << a[i] << " " << freq << endl;
                return "NO";
            }
            else {
                if (isfirst){
                    isfirst = 0;
                    continue;
                }
                else{
                    return "NO";
                }
            }
        }
    }
    return "YES";
}