**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* cur = new ListNode (0);
        ListNode* ans = cur;
        while (l1 != NULL || l2 != NULL || carry) {
            int temp1 = 0, temp2 = 0;
            if (l1 != NULL) {
                temp1 = l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                temp2 = l2->val;
                l2 = l2->next;
            }
            int sum = temp1 + temp2 + carry;
            cur->next = new ListNode (sum % 10);
            carry = sum / 10;
            cur = cur->next;
        }
        return ans->next;
    }
};
