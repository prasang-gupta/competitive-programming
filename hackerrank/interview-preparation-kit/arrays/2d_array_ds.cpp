// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int sum, maxsum;
    for (int i = 0; i < arr.size()-2; ++i){
        for (int j = 0; j < arr[i].size()-2; ++j){
            sum = 0;
            for (int k = 0; k < 3; ++k){
                sum += arr[i][j+k];
                sum += arr[i+2][j+k];
            }
            sum += arr[i+1][j+1];
            if (!i && !j){
                maxsum = sum;
                continue;
            }
            maxsum = (sum > maxsum) ? sum : maxsum;
        }
    }
    return maxsum;
}