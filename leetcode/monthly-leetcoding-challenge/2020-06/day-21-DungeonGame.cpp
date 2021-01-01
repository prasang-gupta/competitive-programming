/*
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

 

Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)	-3	3
-5	-10	1
10	30	-5 (P)
 

Note:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int r = dungeon.size(), c = dungeon[0].size(), minhealth;
        vector <vector <int>> dp(r+1, vector <int> (c+1, 0));
        dp[r][c] = 1;
        
        for (int i = r; i > 0; --i){
            for (int j = c; j > 0; --j){
                minhealth = dp[i][j] - dungeon[i-1][j-1];
                if (minhealth <= 0){
                    dp[i-1][j] = 1;
                    dp[i][j-1] = 1;
                    continue;
                }
                dp[i-1][j] = minhealth;
                if (!dp[i][j-1] || dp[i][j-1] > minhealth){
                    dp[i][j-1] = minhealth;
                }
            }
        }
        
        for (int i = 0; i < r+1; ++i){
            for (int j = 0; j < c+1; ++j){
                cout << dp[i][j] << "\t";
            }
            cout << endl;
        }
        
        return dp[0][1];
    }
};