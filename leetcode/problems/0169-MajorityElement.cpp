/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/

class Solution {
public:
    Solution () {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    }

    int majorityElement(vector<int>& nums) {
        map <int,int> elem;
        map <int,int>::iterator it;
        if (nums.size() == 1){
            return nums[0];
        }
        for (int i = 0; i < nums.size(); ++i){
            it = elem.find(nums[i]);
            if (it == elem.end()){
                elem.insert(pair <int,int> (nums[i], 1));
            }
            else{
                it->second += 1;
                if (it->second > (nums.size()/2)){
                    return it->first;
                }
            }
        }
        return -1;
    }
};