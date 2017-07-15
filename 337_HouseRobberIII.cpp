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
    int rob(TreeNode* root) {
        pair<int, int> r = robSearch(root);
        return max(r.first, r.second);
    }
private:
    pair<int, int> robSearch(TreeNode* cur) {
        if (cur == NULL) {
            return make_pair(0, 0);
        }
        int in = 0, out = 0;
        pair<int, int> l = robSearch(cur->left);
        pair<int, int> r = robSearch(cur->right);
        in = cur->val + l.second + r.second;
        out = max(l.first, l.second) + max(r.first, r.second);
        return make_pair(in, out);
    } 
};