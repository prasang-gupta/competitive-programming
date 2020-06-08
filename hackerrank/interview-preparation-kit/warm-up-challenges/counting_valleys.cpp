// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int curlevel = 0, valley = 0;
    for (int i = 0; i < n; ++i){
        curlevel += (s[i] == 'U') ? 1 : -1;
        if (curlevel == 0 && s[i] == 'U'){
            ++valley;
        }
    }
    return valley;
}