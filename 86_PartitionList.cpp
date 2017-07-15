/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
// Using queue;
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL)   return head;
        ListNode* newhead = new ListNode(0);
        newhead->next = head;
        ListNode* pre = newhead;
        queue<ListNode*> q;
        while (pre->next != NULL) {
            ListNode* cur = pre->next;
            if (cur->val < x) {
                pre = pre->next;
            } else {
                q.push(cur);
                pre->next = cur->next;
            }
        }
        while (!q.empty()) {
            ListNode* cur = q.front();
            q.pop();
            pre->next = cur;
            pre = pre->next;
        }
        pre->next = NULL;
        return newhead->next;
    }
};
*/
// Combine two lists;
class Solution {
public:
    ListNode* partition(ListNode* head, int x) { 
        ListNode node1(0), node2(0);
        ListNode *l1 = &node1, *l2 = &node2;
        while (head) {
            if (head->val < x) {
                l1->next = head;
                l1 = head;
            } else {
                l2->next = head;
                l2 = head;
            }
            head = head->next;
        }
        l1->next = node2.next;
        l2->next = NULL;
        return node1.next;
    }
};
