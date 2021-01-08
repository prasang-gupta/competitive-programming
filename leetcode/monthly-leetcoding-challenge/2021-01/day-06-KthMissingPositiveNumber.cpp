class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int prev = 0, diff;
        for (auto const& a : arr){
            diff = a-prev-1;
            k -= diff;
            cout << a << " " << k << endl;
            if (k <= 0) {
                return a+k-1;
            }
            prev = a;
        }
        return prev + k;
    }
};
