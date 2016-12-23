tion for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> l1_s, l2_s;
        while (l1) {
            l1_s.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            l2_s.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode* temp = new ListNode(0);
        while (!l1_s.empty() || !l2_s.empty()) {
            int l1_num = 0, l2_num = 0;
            if (!l1_s.empty()) {
                l1_num = l1_s.top();
                l1_s.pop();
            }
            if (!l2_s.empty()) {
                l2_num = l2_s.top();
                l2_s.pop();
            }
            temp->val = (l1_num + l2_num + carry) % 10;
            ListNode* head = new ListNode((l1_num + l2_num + carry) / 10);
            head->next = temp;
            temp = head;
            carry = (l1_num + l2_num + carry) / 10;
        }
        return (temp->val == 0 ? temp->next : temp);
    }
};
