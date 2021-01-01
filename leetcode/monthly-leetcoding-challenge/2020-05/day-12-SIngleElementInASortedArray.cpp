/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

Follow up: Your solution should run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 

Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

        int left = 0, right = nums.size()-1, centre;
        
        if (nums.size() == 1){
            return nums[0];
        }
        
        while(right >= left){
            centre = left + (right-left)/2;
            
            if (centre != 0 && centre != nums.size()-1){
                if (nums[centre] != nums[centre-1] && nums[centre] != nums[centre+1]){
                    return nums[centre];
                }
            }
            
            if (centre%2 == 0){
                if (nums[centre] == nums[centre+1]){
                    left = centre + 1;
                }
                else{
                    right = centre - 1;
                }
            }
            else{
                if (nums[centre] == nums[centre-1]){
                    left = centre + 1;
                }
                else{
                    right = centre - 1;
                }
            }
        }
        
        return nums[centre];
    }
};