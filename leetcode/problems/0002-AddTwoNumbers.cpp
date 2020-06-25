/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    Solution () {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = NULL, *lastelem = NULL;
        int carry = 0, sum;
        
        while (l1 != NULL && l2 != NULL){
            sum = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            
            ListNode* newnode = new ListNode(sum);
            if (root == NULL){
                root = newnode;
                lastelem = root;
            }
            else{
                lastelem->next = newnode;
                lastelem = newnode;
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1 != NULL){
            sum = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
            
            ListNode* newnode = new ListNode(sum);
            if (root == NULL){
                root = newnode;
                lastelem = root;
            }
            else{
                lastelem->next = newnode;
                lastelem = newnode;
            }
            
            l1 = l1->next;
        }
        
        while (l2 != NULL){
            sum = (l2->val + carry) % 10;
            carry = (l2->val + carry) / 10;
            
            ListNode* newnode = new ListNode(sum);
            if (root == NULL){
                root = newnode;
                lastelem = root;
            }
            else{
                lastelem->next = newnode;
                lastelem = newnode;
            }
            
            l2 = l2->next;
        }
        
        if (carry) {
            ListNode* newnode = new ListNode(carry);
            if (root == NULL){
                root = newnode;
                lastelem = root;
            }
            else{
                lastelem->next = newnode;
                lastelem = newnode;
            }
        }
        
        return root;
    }
};