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
    ListNode *detectCycle(ListNode *head) {
        ListNode *oneStep = head, *twoStep = head;
        bool isCircle = false;
        while (twoStep != NULL && twoStep->next != NULL) {
            oneStep = oneStep->next;
            twoStep = twoStep->next->next;
            if (oneStep == twoStep) {
                isCircle = true;
                break;
            }
        }
        if (!isCircle) return NULL;
        while (head != oneStep) {
            head = head->next;
            oneStep = oneStep->next;
        }
        return head;
    }
};