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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        stack<TreeNode*> s;
        TreeNode* temp = root;
        while (temp != NULL || !s.empty()) {
            if (temp) {
                ans.push_back(temp->val);
                s.push(temp);
                temp = temp->left;
            } else {
                temp = s.top()->right;
                s.pop();
            }
        }
        return ans;
    }
};
