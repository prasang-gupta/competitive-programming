/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    }
    
    vector <vector <int> > ans;
    
    void make_reverse_tree (TreeNode* root, int depth) {
        if (root == NULL){
            return;
        }
        
        if (ans.size() < depth){
            vector <int> temp;
            temp.push_back(root->val);
            ans.push_back(temp);
        }
        else{
            ans[depth-1].push_back(root->val);
        }
        
        make_reverse_tree (root->left, depth + 1);
        make_reverse_tree (root->right, depth + 1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector <int> temp;
        
        make_reverse_tree (root, 1);
        reverse (ans.begin(), ans.end());
        
        return ans;
    }
};