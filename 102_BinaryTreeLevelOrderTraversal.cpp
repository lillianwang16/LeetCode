/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
 // BSF solution.
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root == NULL) {
            return ans;
        }
        q.push(root);
        while (!q.empty()) {
            int cnt = q.size();
            vector<int> temp;
            TreeNode* cur;
            for (int i = 0; i < cnt; ++i) {
                cur = q.front();
                q.pop();
                temp.push_back(cur->val);
                if (cur->left != NULL) {
                    q.push(cur->left);
                }
                if (cur->right != NULL) {
                    q.push(cur->right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
*/
//DFS solution.
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelOrder(root, ans, 0);
        return ans;
    }
    void levelOrder(TreeNode* root, vector<vector<int>> &ans, int height) {
        if (root == NULL) {
            return;
        }
        if (height == ans.size()) {
            ans.push_back(vector<int>());
        }
        ans[height].push_back(root->val);
        levelOrder(root->left, ans, height + 1);
        levelOrder(root->right, ans, height + 1);
    }
};
