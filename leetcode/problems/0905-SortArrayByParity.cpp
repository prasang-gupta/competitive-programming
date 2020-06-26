/*
Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 

Note:

1 <= A.length <= 5000
0 <= A[i] <= 5000
*/

class Solution {
public:
    Solution () {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    }
    
    vector<int> sortArrayByParity(vector<int>& A) {
        int left = 0, right = A.size()-1, l, r;
        while (left < right){
            l = A[left] % 2;
            r = A[right] % 2;
            if (l == 0){
                if (r == 0){
                    left++;
                }
                else{
                    left++;
                    right--;
                }
            }
            else{
                if (r == 0){
                    int temp = A[left];
                    A[left] = A[right];
                    A[right] = temp;
                    left++;
                    right--;
                }
                else{
                    right--;
                }
            }
        }
        return A;
    }
};