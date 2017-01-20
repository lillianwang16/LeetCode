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
    ListNode* oddEvenList(ListNode* head) {
       int n = 0;       
       ListNode *cur = head;
       while (cur != NULL) {
           cur = cur -> next;
           ++n;
       }
       for (int i = 0; i < n / 2; ++i) {
           cur = head;
           for(int j = 0; j < i; ++j) {
               cur = cur -> next;
           }
           int cnt = i;
           while (cnt + i + 2 < n) {
               ListNode* temp1 = cur->next;
               cur->next = temp1->next;
               cur = cur->next;
               ListNode* temp2 = cur->next;
               cur->next  = temp1;
               cur = cur->next;
               cur->next = temp2;
               cnt += 2;
           } 
       }
       return head;
    }
};
*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode* odd = head, *even = head->next, *even_head = even;
        while (even != NULL && even->next != NULL) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = even_head;
        return head;
    }
};
