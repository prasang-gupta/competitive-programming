// Complete the minimumAbsoluteDifference function below.
int minimumAbsoluteDifference(vector<int> arr) {
    sort(arr.begin(), arr.end());

    long mindiff = abs(arr[1]-arr[0]);
    for (int i = 1; i < arr.size(); ++i){
        if (mindiff > abs(arr[i] - arr[i-1])){
            mindiff = abs(arr[i] - arr[i-1]);
        }
    }
    return mindiff;
}