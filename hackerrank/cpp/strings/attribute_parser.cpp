int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n, q;
    string s, stacktag = "";
    vector <string> tag, key, val;

    cin >> n >> q;
    while(n--){
        getline(cin, s);
        if (s == ""){
            n++;
            continue;
        }
        
        int tagdone = 0, keydone = 0, valdone = 0, startidx = 1;
        string curtag, curkey, curval;
        if (s[1] != '/'){
            for (int i = 1; i < s.size(); ++i){
                if (tagdone == 0 && (s[i] == '>' || s[i] == ' ')){
                    tagdone = 1;
                    if (s[i] == '>'){
                        curtag = s.substr(startidx, i - startidx);
                        if (stacktag == ""){
                            stacktag = curtag;
                        }
                        else{
                            stacktag += ".";
                            stacktag += curtag;
                        }
                        break;
                    }
                    curtag = s.substr(startidx, i - startidx);
                    if (stacktag == ""){
                        stacktag = curtag;
                    }
                    else{
                        stacktag += ".";
                        stacktag += curtag;
                    }
                    startidx = i+1;
                    continue;
                }
                if (keydone == 0 && s[i] == ' ' && s[i+1] == '='){
                    keydone = 1;
                    curkey = s.substr(startidx, i - startidx);
                    startidx = i+4;
                    i += 3;
                    continue;
                }
                if (valdone == 0 && s[i] == '"'){
                    keydone = 0;
                    valdone = 0;
                    curval = s.substr(startidx, i - startidx);
                    tag.push_back(stacktag);
                    key.push_back(curkey);
                    val.push_back(curval);
                    startidx = i+2;
                    i++;
                }
            }
        }
        else{
            for (int i = 0; i < s.size(); ++i){
                if (s[i] == '>'){
                    for (startidx = stacktag.size()-1; startidx >= 0; --startidx){
                        if (stacktag[startidx] == '.'){
                            break;
                        }
                    }
                    stacktag = (startidx == -1) ? "" : stacktag.substr(0, startidx);
                }
            }
        }
    }
    
    while(q--){
        getline(cin, s);
        if (s == ""){
            q++;
            continue;
        }

        string curtag, curkey;
        int tildefound = 0;
        for (int i = 0; i < s.size(); ++i){
            if (s[i] == '~'){
                tildefound = 1;
                curtag = s.substr(0, i);
                curkey = s.substr(i+1, s.size()-i);
                n = 0;
                for (int t = 0; t < tag.size(); ++t){
                    if (tag[t] == curtag && key[t] == curkey){
                        n = 1;
                        cout << val[t] << endl;
                        break;
                    }
                }
                if (n == 0){
                    cout << "Not Found!" << endl;
                }
                else{
                    break;
                }
            }
        }
        if (tildefound == 0){
            cout << "Not Found!" << endl;
        }
    }
    return 0;
}
