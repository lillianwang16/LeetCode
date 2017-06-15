/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 /*
 // Brute force.
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        RandomListNode* newhead = new RandomListNode(head->label);;
        RandomListNode* cur1 = head->next, *cur2 = newhead;
        while (cur1 != NULL) {
            cur2->next = new RandomListNode(cur1->label);
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        cur1 = head;
        cur2 = newhead;
        while (cur1 != NULL) {
            if (cur1->random != NULL) {
                 RandomListNode* temp1 = head, *temp2 = newhead;
                 while (temp1 != cur1->random) {
                     temp1 = temp1->next;
                     temp2 = temp2->next;
                 }
                 cur2->random = temp2;
            }
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return newhead;
    }
};
*/

//One signle linked list.
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) { 
        RandomListNode *cur = head, *next;
        while (cur != NULL) {
            next = cur->next;
            cur->next = new RandomListNode(cur->label);
            cur->next->next = next;
            cur = cur->next->next;
        }
        cur = head;
        while (cur != NULL) {
            if (cur->random != NULL) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        RandomListNode *newhead = new RandomListNode(0);
        RandomListNode *cur_copy = newhead;
        cur = head;
        while (cur != NULL) {
            next = cur->next->next;
            cur_copy->next = cur->next;
            cur_copy = cur_copy->next;
            cur->next = next;
            cur = cur->next;
        }
        return newhead->next;
    }
};