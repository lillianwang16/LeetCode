/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* root = sort(head, NULL);
        return root;
    }
private:
    TreeNode* sort(ListNode* start, ListNode* end) {
        if (start == end) return NULL;
        if (start == end) {
            return new TreeNode(start->val);
        }
        ListNode* p1 = start, *p2 = start;
        while (p2->next != end && p2->next->next != end) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        TreeNode* cur = new TreeNode(p1->val);
        cur->left = sort(start, p1);
        cur->right = sort(p1->next, end);
        return cur;
    }
};