/*
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

        vector <vector <int>> sum(matrix.size(), vector <int> (matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); ++i){
            for (int j = 0; j < matrix[i].size(); ++j){
                if (i == 0){
                    sum[i][j] = matrix[i][j];
                }
                else{
                    sum[i][j] = matrix[i][j] + sum[i-1][j];
                }
            }
        }
        for (int i = 0; i < sum.size(); ++i){
            for (int j = 0; j < sum[i].size(); ++j){
                if (j == 0){
                    sum[i][j] = sum[i][j];
                }
                else{
                    sum[i][j] = sum[i][j] + sum[i][j-1];
                }
            }
        }
        
        int max_size = min(matrix.size(), matrix[0].size());
        
        int score, count = 0;
        for (int size = 1; size <= max_size; ++size){
            for (int i = size-1; i < sum.size(); ++i){
                for (int j = size-1; j < sum[i].size(); ++j){
                    score = sum[i][j];
                    if (i >= size && j >= size){
                        score -= sum[i-size][j] + (sum[i][j-size] - sum[i-size][j-size]);
                    }
                    else if (i >= size){
                        score -= sum[i-size][j];
                    }
                    else if (j >= size){
                        score -= sum[i][j-size];
                    }
                    if (score == pow(size,2)) {
                        ++count;
                    }
                }
            }
        }
        return count;
    }
};