// Complete the maximumSum function below.
long maximumSum(vector<long> a, long m) {
    long sum = 0, minval = LONG_MAX, maxval;
    set <long> s;

    maxval = a[0] % m;
    for (int i = 0; i < a.size(); ++i){
        sum = (sum + a[i]) % m;
        a[i] = sum;
        maxval = max(maxval, sum);
    }

    for (int i = 0; i < a.size(); ++i){
        auto p = s.insert(a[i]);
        if (++p.first != s.end()){
            minval = min(*p.first - a[i], minval);
        }
    }

    return max(m - minval, maxval);
}