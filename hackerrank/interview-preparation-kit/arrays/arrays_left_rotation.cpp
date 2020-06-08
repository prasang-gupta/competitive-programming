// Complete the rotLeft function below.
vector<int> rotLeft(vector<int> a, int d) {
    vector <int> result(a.size());
    d = d%a.size();
    int k = 0;
    for (int i = d; i < a.size(); ++i){
        result[k++] = a[i];
    }
    for (int i = 0; i < d; ++i){
        result[k++] = a[i];
    }
    return result;
}