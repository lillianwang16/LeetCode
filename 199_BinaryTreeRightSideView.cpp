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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        right(res, root, 0);
        return res;
    }
private:
    void right(vector<int>& res, TreeNode* cur, int depth) {
        if (cur == NULL) {
            return;
        }
        if (res.size() <= depth) {
            res.push_back(cur->val);
        }
        if (cur->right != NULL)     right(res, cur->right, depth + 1);
        if (cur->left  != NULL)     right(res, cur->left,  depth + 1);
    }
};