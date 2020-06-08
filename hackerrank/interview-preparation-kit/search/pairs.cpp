// Complete the pairs function below.
int pairs(int k, vector<int> arr) {
    map <int, bool> m;

    for (int i = 0; i < arr.size(); ++i){
        m[arr[i]] = true;
    }

    int count = 0;
    for (int i = 0; i < arr.size(); ++i){
        if (arr[i] - k > 0){
            auto it = m.find(arr[i]-k);
            if (it == m.end()){
                continue;
            }
            ++count;
        }
    }
    return count;
}