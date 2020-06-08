// Complete the whatFlavors function below.
void whatFlavors(vector<int> cost, int money) {
    map <int, int> m;

    for (int i = 0; i < cost.size(); ++i){
        m[cost[i]] = i+1;
    }

    for (int i = 0; i < cost.size(); ++i){
        if (money - cost[i] > 0){
            auto it = m.find(money - cost[i]);
            if (it != m.end()){
                if (it->second == i+1){
                    continue;
                }
                cout << i+1 << " " << it->second << endl;
                return;
            }
        }
    }
}