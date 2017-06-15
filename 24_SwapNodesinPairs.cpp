/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
// Iterative solution.
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* first = head, *second = head->next;
        ListNode* newhead = second;
        ListNode* last = new ListNode(0);
        while (first != NULL && second != NULL) {
            first->next = second->next;
            second->next = first;
            last->next = second;
            last = first;
            first = first->next;
            if (first != NULL) {
                second = first->next;
            }
        }
        return newhead;
    }
};
*/

// Recursive solution.
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* newhead = head->next;
        head->next = swapPairs(head->next->next);
        newhead->next = head;
        return newhead;
    }
};