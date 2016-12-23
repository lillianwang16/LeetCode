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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return sumOfLeftLeaves(root, false);
    }
private:
    int sumOfLeftLeaves(TreeNode* root, bool left_node) {
        if (!root->left && !root->right) {
            if (left_node) {
                return root->val;
            } else {
                return 0;
            }
        }
        int sum_left = 0, sum_right = 0;
        if (root->left) {
             sum_left = sumOfLeftLeaves(root->left, true);
        }
        if (root->right) {
             sum_right = sumOfLeftLeaves(root->right, false);
        }
        return sum_left + sum_right ;
    }
};
