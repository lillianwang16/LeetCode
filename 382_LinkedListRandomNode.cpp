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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
/*
    Solution(ListNode* head): head_(head) {
        ListNode* temp = head_;
        while (temp) {
            ++num_node_;
            temp = temp->next;
        }
    }
*/   
    /** Returns a random node's value. */
/*    
    int getRandom() {
        int num_random = rand() % num_node_ + 1;
        ListNode* temp = head_;
        for (int i = 1; i < num_random; ++i) {
            temp = temp -> next;
        }
        return temp->val;
    }
*/

    Solution(ListNode* head): head_(head) {
        
    }
    int getRandom() {
        int ans = head_->val;
        ListNode* temp = head_->next;
        int i = 2, num_random = 0;
        while (temp) {
            num_random = rand() % i;
            if (!num_random) {
                ans = temp->val;
            }
            temp = temp->next;
            ++i;
        }
        return ans;
    }
    private:
    ListNode* head_;
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
