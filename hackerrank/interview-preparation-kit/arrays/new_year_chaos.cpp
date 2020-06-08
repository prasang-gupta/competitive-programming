// Complete the minimumBribes function below.
void minimumBribes(vector<int> q) {
    int sum = 0, diff;
    for (int i = 0; i < q.size(); ++i){
        if (q[i]-(i+1) > 2){
            cout << "Too chaotic" << endl;
            return;
        }
        for (int j = i-1; j >= max(q[i]-2,0); j--){
            if (q[j] > q[i]){
                ++sum;
            }
        }
    }
    cout << sum << endl;
}