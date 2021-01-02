/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans = NULL;
    bool found = false;
    
    void dfs(TreeNode* root, int target){
        if (root == NULL){
            return;
        }
        if (root->val == target){
            ans = root;
            found = true;
        }
        if (!found){
            dfs(root->left, target);
        }
        if (!found){
            dfs(root->right, target);
        }
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        dfs(cloned, target->val);
        if (found){
            return ans;
        }
        return NULL;
    }
};
