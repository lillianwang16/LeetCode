/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /*
 //Iterative solution.
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* newhead = new ListNode(0);
        ListNode* cur = newhead;
        while (l1 != NULL || l2 != NULL) {
            if (l1 == NULL) {
                cur->next = l2;
                break;
            } else if (l2 == NULL) {
                cur->next = l1;
                break;
            } else if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }
        return newhead->next;
    }
};
*/

// Recursive solution.
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* newhead;
        if (l1 == NULL) {
            newhead = l2;
        } else if (l2 == NULL) {
            newhead = l1;
        } else if (l1->val < l2->val) {
            newhead = l1;
            l1->next = mergeTwoLists(l1->next, l2);
        } else {
            newhead = l2;
            l2->next = mergeTwoLists(l1, l2->next);
        }
        return newhead;
    }
};