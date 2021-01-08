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
    ListNode* deleteDuplicates(ListNode* head) {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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
