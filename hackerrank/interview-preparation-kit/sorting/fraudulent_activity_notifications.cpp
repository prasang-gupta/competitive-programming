// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
    vector <int> his(expenditure.begin(), expenditure.begin()+d);
    sort(his.begin(), his.end());
    int count = 0;

    for (int i = d; i < expenditure.size(); ++i){
        if (d % 2 == 0){
            if (expenditure[i] >= (his[d/2] + his[d/2-1])){
                ++count;
            }
        }
        else{
            if (expenditure[i] >= 2*his[d/2]){
                ++count;
            }
        }

        auto it = find(his.begin(), his.end(), expenditure[i-d]);
        his.erase(it);
        his.insert(lower_bound(his.begin(), his.end(), expenditure[i]), expenditure[i]);
    }
    return count;
}