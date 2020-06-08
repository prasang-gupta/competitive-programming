// Complete the triplets function below.
long triplets(vector<int> a, vector<int> b, vector<int> c) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    int lastelem = a[0];
    vector <int> temp;
    temp.push_back(lastelem);
    for (int i = 1; i < a.size(); ++i){
        if (a[i] != lastelem){
            lastelem = a[i];
            temp.push_back(lastelem);
        }
    }
    a = temp;
    
    temp.clear();
    lastelem = b[0];
    temp.push_back(lastelem);
    for (int i = 1; i < b.size(); ++i){
        if (b[i] != lastelem){
            lastelem = b[i];
            temp.push_back(lastelem);
        }
    }
    b = temp;

    temp.clear();
    lastelem = c[0];
    temp.push_back(lastelem);
    for (int i = 1; i < c.size(); ++i){
        if (c[i] != lastelem){
            lastelem = c[i];
            temp.push_back(lastelem);
        }
    }
    c = temp;

    long count = 0;
    for (int i = 0; i < b.size(); ++i){
        count += (upper_bound(a.begin(), a.end(), b[i]) - a.begin()) * (upper_bound(c.begin(), c.end(), b[i]) - c.begin());
    }
    return count;
}