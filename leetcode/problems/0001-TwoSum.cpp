/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

class Solution {
public:
    Solution () {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int, int> m;
        vector <int> ans(2, 0);
        
        for (int i = 0; i < nums.size(); ++i){
            auto elem = m.find(target - nums[i]);
            if (elem != m.end()){
                ans[0] = elem->second;
                ans[1] = i;
                return ans;
            }
            m[nums[i]] = i;
        }
        return ans;
    }
};