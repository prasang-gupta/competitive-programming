/*
Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

 

Example 1:


Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: l1 = [], l2 = []
Output: []
Example 3:

Input: l1 = [], l2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both l1 and l2 are sorted in non-decreasing order.
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
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode();
        ListNode* cur = root;
        while (l1 != nullptr && l2 != nullptr){
            if (l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }
        while (l1 != nullptr){
            cur->next = l1;
            l1 = l1->next;
            cur = cur->next;
        }
        while (l2 != nullptr){
            cur->next = l2;
            l2 = l2->next;
            cur = cur->next;
        }
        return root->next;
    }
};
