// Complete the maxMin function below.
int maxMin(int k, vector<int> arr) {
    sort(arr.begin(), arr.end());

    int minunf = arr[k-1] - arr[0];
    for (int i = k-1; i < arr.size(); ++i){
        if (minunf > arr[i] - arr[i-k+1]){
            minunf = arr[i] - arr[i-k+1];
        }
    }
    return minunf;
}