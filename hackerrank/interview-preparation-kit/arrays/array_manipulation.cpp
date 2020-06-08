// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {
    long *arr;
    arr = new long[n+1];

    for (long i = 0; i < queries.size(); ++i){
        arr[queries[i][0]-1] += queries[i][2];
        arr[queries[i][1]] -= queries[i][2];
    }

    long sum = 0, maxsum = arr[0];
    for (int i = 0; i < n+1; ++i){
        sum += arr[i];
        if (sum > maxsum){
            maxsum = sum;
        }
    }
    return maxsum;
}