// Complete the substrCount function below.
long substrCount(int n, string s) {
    vector <int> val;
    vector <char> key;

    char curchar;
    long curcount = -1;
    for (int i = 0; i < n; ++i){
        if (curcount == -1){
            curchar = s[i];
            curcount = 1;
            continue;
        }
        if (s[i] != curchar){
            key.push_back(curchar);
            val.push_back(curcount);
            curchar = s[i];
            curcount = 1;
            continue;
        }
        curcount++;
    }
    key.push_back(curchar);
    val.push_back(curcount);
    
    long count = 0;
    for (int i = 0; i < val.size(); ++i){
        count += (val[i]*(val[i]+1))/2;
    }
    for (int i = 1; i < val.size()-1; ++i){
        if (key[i-1] == key[i+1] && val[i] == 1){
            count += min(val[i-1], val[i+1]);
        }
    }
    return count;
}