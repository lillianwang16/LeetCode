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
    struct cmp {
        bool operator() (const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* start = new ListNode(0);
        ListNode* cur = start;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }
        while (!pq.empty()) {
            cur->next = pq.top();
            cur = cur->next;
            ListNode* temp = pq.top();
            pq.pop();
            if (temp->next != NULL) {
                pq.push(temp->next);
            }
        } 
        return start->next;
    }
};
