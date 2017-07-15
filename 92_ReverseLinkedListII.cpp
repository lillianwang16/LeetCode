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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        int cnt = 1;
        ListNode *cur = newHead;
        while (cnt < m) {
            cur = cur->next;
            ++cnt;
        }
        if (cur->next == NULL || cur->next->next == NULL) return head;
        ListNode *pre = cur, *first = cur->next;
        while (cnt < n) {
            ListNode* temp = first->next;
            first->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
            ++cnt;
        }
        return newHead->next;
    }
};