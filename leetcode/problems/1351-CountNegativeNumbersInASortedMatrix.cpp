/*
Given a m * n matrix grid which is sorted in non-increasing order both row-wise and column-wise. 

Return the number of negative numbers in grid.

 

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0
Example 3:

Input: grid = [[1,-1],[-1,-1]]
Output: 3
Example 4:

Input: grid = [[-1]]
Output: 1
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100
*/

class Solution {
public:
    Solution () {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    }
    
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0, n = grid.size(), m = grid[0].size();
        for (int i = n-1; i >= 0; --i){
            if (grid[i][m-1] >= 0){
                break;
            }
            
            for (int j = m-1; j >= 0; --j){
                if (grid[i][j] < 0){
                    ++count;
                }
                else{
                    break;
                }
            }
        }
        return count;
    }
};