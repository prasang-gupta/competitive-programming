/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Constraints:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    Solution () {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        vector <TreeNode*> queue;
        queue.push_back(root);
        int x_matched = 0, y_matched = 0, xidx = -1, yidx = -1;
        
        while(1){
            vector <TreeNode*> temp;
            int nullcount = 0;
            for (int i = 0; i < queue.size(); ++i){
                if (queue[i] == NULL){
                    nullcount += 1;
                    continue;
                }
                if (x == queue[i]->val){
                    x_matched = 1;
                    xidx = i;
                }
                if (y == queue[i]->val){
                    y_matched = 1;
                    yidx = i;
                }
                temp.push_back(queue[i]->left);
                temp.push_back(queue[i]->right);
            }
            if (x_matched || y_matched){
                if (x_matched && y_matched){
                    if (abs(xidx-yidx) == 1 && max(xidx, yidx)%2 != 0){
                        return false;
                    }
                    else{
                        return true;
                    }
                }
                else{
                    return false;
                }
            }
            if (nullcount == queue.size()){
                break;
            }
            queue = temp;
        }
        return false;
    }
};