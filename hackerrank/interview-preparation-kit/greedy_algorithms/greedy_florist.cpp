// Complete the getMinimumCost function below.
int getMinimumCost(int k, vector<int> c) {
    int cost = 0;

    sort(c.begin(), c.end(), greater <int>());
    for (int i = 0; i < c.size(); ++i){
        cost += ((int)(i/k) + 1) * c[i]; 
    }
    return cost;
}