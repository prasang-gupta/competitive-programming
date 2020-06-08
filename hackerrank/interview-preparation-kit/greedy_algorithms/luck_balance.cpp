// Complete the luckBalance function below.
int luckBalance(int k, vector<vector<int>> contests) {
    vector <int> imp;
    int balance = 0;
    for (int i = 0; i < contests.size(); ++i){
        if (contests[i][1]){
            imp.push_back(contests[i][0]);
        }
        else{
            balance += contests[i][0];
        }
    }

    sort(imp.begin(), imp.end());

    for (int i = imp.size()-1; i >= 0; --i){
        balance += (k-- > 0) ? imp[i] : -imp[i];
    }
    return balance;
}