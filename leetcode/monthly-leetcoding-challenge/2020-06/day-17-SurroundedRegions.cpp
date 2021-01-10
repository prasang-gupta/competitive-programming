/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/

class Solution {
public:
    Solution () {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    }
    
    void change_boundary_connected_vals (vector <vector <char> > &a, const int r, const int c, int i, int j) {
        a[i][j] = 'Z';
        if (i > 0 && a[i-1][j] == 'O'){
            change_boundary_connected_vals(a, r, c, i-1, j);
        }
        if (j > 0 && a[i][j-1] == 'O'){
            change_boundary_connected_vals(a, r, c, i, j-1);
        }
        if (i+1 < r && a[i+1][j] == 'O'){
            change_boundary_connected_vals(a, r, c, i+1, j);
        }
        if (j+1 < c && a[i][j+1] == 'O'){
            change_boundary_connected_vals(a, r, c, i, j+1);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        const int r = board.size();
        if (!r)
            return;
        
        const int c = board[0].size();
        if (!c)
            return;
        
        for (int j = 0; j < c; ++j){
            if (board[0][j] == 'O'){
                change_boundary_connected_vals(board, r, c, 0, j);
            }
            if (board[r-1][j] == 'O'){
                change_boundary_connected_vals(board, r, c, r-1, j);
            }
        }
        
        for (int i = 0; i < r; ++i){
            if (board[i][0] == 'O'){
                change_boundary_connected_vals(board, r, c, i, 0);
            }
            if (board[i][c-1] == 'O'){
                change_boundary_connected_vals(board, r, c, i, c-1);
            }
        }
        
        for (int i = 0; i < r; ++i){
            for (int j = 0; j < c; ++j){
                if (board[i][j] == 'Z'){
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};