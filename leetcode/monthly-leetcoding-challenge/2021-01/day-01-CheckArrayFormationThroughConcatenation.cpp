class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < arr.size(); ++i){
            int flag = 0;
            for (int j = 0; j < pieces.size(); ++j){
                if (arr[i] == pieces[j][0]){
                    flag = 1;
                    for (int k = 0; k < pieces[j].size(); ++k){
                        if (arr[i] != pieces[j][k]){
                            return false;
                        }
                        ++i;
                    }
                    --i;
                    break;
                }
            }
            if (flag == 0){
                return false;
            }
        }
        return true;
    }
};
