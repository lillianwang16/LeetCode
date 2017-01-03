/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
//One solution using stack
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        stack<ListNode*> my_stack;
        ListNode* temp = head;
        while (temp != NULL) {
            my_stack.push(temp);
            temp = temp->next;
        }
        temp = my_stack.top();
        ListNode* ans = temp;
        my_stack.pop();
        while (!my_stack.empty()) {
            temp->next = my_stack.top();
            temp = my_stack.top();
            my_stack.pop();
        }
        temp->next = NULL;
        return ans;
    }
};
*/
/*
//Another solution using recursion
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return reverseList_helper(NULL, head);
    }
private:
    ListNode* reverseList_helper(ListNode* node1, ListNode* node2) {
        if (node2 == NULL) {
            return node1;
        }
        ListNode* temp = node2->next;
        node2->next = node1;
        return reverseList_helper(node2, temp);
    }
};
*/
// Another solution using iteration.
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* new_next = NULL;
        while (head != NULL) {
            ListNode* next = head->next;
            head->next = new_next;
            new_next = head;
            head = next;
        }
        return new_next;
    }
};
