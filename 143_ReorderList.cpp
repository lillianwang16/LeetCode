/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
//Using stack.
class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        int cnt = 0;
        ListNode* cur = head;
        while (cur != NULL) {
            st.push(cur);
            cur = cur->next;
            ++cnt;
        }
        if (cnt <= 2) return;
        bool flag = cnt % 2;
        cur = head;
        cnt = (cnt - 1) / 2; 
        while (cnt > 0) {
            ListNode* temp = cur->next;
            cur->next = st.top();
            st.pop();
            cur->next->next = temp;
            cur = cur->next->next;
            --cnt;
        }
        if (!flag) {
            cur = cur->next;
        }
        cur->next = NULL;
    }
};
*/

// Reverse linked list.
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;
        ListNode *p1 = head, *p2 = head;
        while (p2->next != NULL && p2->next->next != NULL) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        ListNode *preMiddle = p1;
        ListNode *newTail = p1->next;
        while (newTail->next != NULL) {
            ListNode *cur = newTail->next;
            newTail->next = cur->next;
            cur->next = preMiddle->next;
            preMiddle->next = cur;
        }
        p1 = head;
        p2 = preMiddle->next;
        while (p1 != preMiddle) {
            ListNode* temp1 = p1->next;
            ListNode* temp2 = p2->next;
            p1->next = p2;
            p2->next = temp1;
            preMiddle->next = temp2;
            p1 = temp1;
            p2 = temp2;
        }
    }
};