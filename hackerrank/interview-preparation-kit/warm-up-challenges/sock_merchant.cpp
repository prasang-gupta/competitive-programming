// Complete the sockMerchant function below.
int sockMerchant(int n, vector<int> ar) {
    vector <bool> socks(101,false);
    int result = 0;
    for (int i = 0; i < n; ++i){
        if (socks[ar[i]] == false){
            socks[ar[i]] = true;
        }
        else{
            socks[ar[i]] = false;
            ++result;
        }
    }
    return result;
}