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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)   return head;
        ListNode *tail = head, *newhead;
        int cnt = 1;
        while (tail->next != NULL) {
            ++cnt;
            tail = tail->next;
        }
        tail->next = head;
        if (k % cnt != 0) {
            k = cnt - k % cnt;
            while (k > 0) {
                tail = tail->next;
                --k;
            }
        }
        newhead = tail->next;
        tail->next = NULL;
        return newhead;
    }
};
