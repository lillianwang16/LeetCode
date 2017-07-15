/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)   return head;
        ListNode* newhead = new ListNode(0), *pre, *cur;
        newhead->next = head;
        pre = newhead; 
        cur = pre->next;
        while (cur != NULL) {
            ListNode *n = cur->next;
            int cnt = 1;
            while (n != NULL && n->val == cur->val) {
                n = n->next;
                ++cnt;
            }
            if (cnt == 1) {
                pre->next = cur;
                pre = pre->next;
            }
            cur = n;
        }
        if (pre != NULL) pre->next = NULL;
        return newhead->next;
    }
};