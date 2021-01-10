/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
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
    
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* root = new ListNode(0, head);
        ListNode* last = root, *cur = head;
        while (cur != nullptr){
            bool repeat = false;
            while (cur->next != nullptr && cur->val == cur->next->val){
                repeat = true;
                cur = cur->next;
            }
            if (!repeat){
                last->next = cur;
                last = cur;
                cur = cur->next;
            }
            else{
                last->next = cur->next;
                cur = cur->next;
            }
        }
        return root->next;
    }
};
