/*
Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

Example 1:

Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
 

Note: The merging process must start from the root nodes of both trees.
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
    
    void merge (TreeNode* root, TreeNode* t1, TreeNode* t2) {
        if (t1 != NULL){
            root->val += t1->val;
        }
        if (t2 != NULL){
            root->val += t2->val;
        }
        
        if ((t1 != NULL && t1->left != NULL) || (t2 != NULL && t2->left != NULL)){
            root->left = new TreeNode;
            if ((t1 != NULL && t1->left != NULL) && (t2 != NULL && t2->left != NULL)){
                merge (root->left, t1->left, t2->left);
            }
            else if (t1 != NULL && t1->left != NULL){
                merge (root->left, t1->left, NULL);
            }
            else{
                merge (root->left, NULL, t2->left);
            }
        }
        
        if ((t1 != NULL && t1->right != NULL) || (t2 != NULL && t2->right != NULL)){
            root->right = new TreeNode;
            if ((t1 != NULL && t1->right != NULL) && (t2 != NULL && t2->right != NULL)){
                merge (root->right, t1->right, t2->right);
            }
            else if (t1 != NULL && t1->right != NULL){
                merge (root->right, t1->right, NULL);
            }
            else{
                merge (root->right, NULL, t2->right);
            }
        }
    }
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL){
            return t1;
        }
        
        TreeNode* root = new TreeNode;
        merge (root, t1, t2);
        return root;
    }
};