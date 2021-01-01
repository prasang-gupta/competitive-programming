/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        if (!nums.size()){
            return nums;
        }
        
        sort(nums.begin(), nums.end());
        
        vector <int> count(nums.size(), 1);
        vector <int> prev(nums.size(), -1);
        int maxidx = 0;
        
        for (int i = 1; i < nums.size(); ++i){
            for (int j = 0; j < i; ++j){
                if (nums[i] % nums[j] == 0){
                    if (count[i] < count[j] + 1){
                        count[i] = count[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if (count[maxidx] < count[i]){
                maxidx = i;
            }
        }
        
        vector <int> ans;
        int idx = maxidx;
        while (idx >= 0){
            ans.push_back(nums[idx]);
            idx = prev[idx];
        }
        return ans;
    }
};