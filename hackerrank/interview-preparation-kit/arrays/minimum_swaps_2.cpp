// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
    vector <int> dict(arr.size(), -1);
    vector <bool> vis(arr.size(), false);
    int idx, sum = 0, count;

    for (int i = 0; i < arr.size(); ++i){
        dict[i] = arr[i]-1;
    }

    for (int i = 0; i < dict.size(); ++i){
        idx = i;
        count = 0;
        do{
            vis[idx] = true;
            idx = dict[idx];
            ++count;
        } while (vis[idx] == false);

        sum += count-1;
    }
    return sum;
}