// Complete the maximumToys function below.
int maximumToys(vector<int> prices, int k) {
    sort(prices.begin(), prices.end());

    for (int i = 0; i < prices.size(); ++i){
        k -= prices[i];
        if (k < 0){
            return i;
        }
    }
    return 0;
}