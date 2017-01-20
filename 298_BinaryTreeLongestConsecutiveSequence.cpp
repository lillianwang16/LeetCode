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
    int longestConsecutive(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        longestConsecutive(root, 1);
        return ans;
    }
private:
    int ans = 0;
    void longestConsecutive(TreeNode* root, int cnt) {
        if (root == NULL) {
            ans = max(ans, cnt);
            return;
        }
        if (root->left != NULL && root->left->val == root->val + 1) {
            longestConsecutive(root->left, cnt + 1);
        } else {
            ans = max(ans, cnt);
            longestConsecutive(root->left, 1);
        }
        if (root->right != NULL && root->right->val == root->val + 1) {
            longestConsecutive(root->right, cnt + 1);
        } else {
            ans = max(ans, cnt);
            longestConsecutive(root->right, 1);
        }
    }
};
