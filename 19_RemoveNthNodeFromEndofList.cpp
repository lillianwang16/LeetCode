/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int step = 0;
        removeNthFromEnd(head, n, step);
        if (step == n) {
            return head->next;
        }
        return head;
    }
private:
    void removeNthFromEnd(ListNode* cur, int n, int& step) {
        if (cur == NULL) {
            return;
        }
        removeNthFromEnd(cur->next, n, step);
        if (step++ == n) {
            cur->next = cur->next->next;
        }
    }
};
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *start = new ListNode(0);
        start->next = head;
        ListNode *slow = start, *fast = start;
        for (int i = 0; i < n + 1; ++i) {
            fast = fast->next;
        }
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return start->next;
    }
};
