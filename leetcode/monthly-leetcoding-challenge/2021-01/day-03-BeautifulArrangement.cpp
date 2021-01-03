class Solution {
public:
    long long int ans = 0;
    bool used[16];
    
    void dfs(int n, int idx){
        if (idx > n){
            ans++;
            return;
        }
        for (int i = 1; i <= n; ++i){
            if (!used[i] && (idx%i == 0 || i%idx == 0)){
                used[i] = true;
                dfs(n, idx+1);
                used[i] = false;
            }
        }
    }
    
    int countArrangement(int n) {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        for (int i = 0; i < 16; ++i){
            used[i] = false;
        }
        dfs(n, 1);
        return ans;
    }
};
