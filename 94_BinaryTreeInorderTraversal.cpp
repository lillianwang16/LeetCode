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
    /*
    vector<int> inorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*, bool>> my_stack;
        my_stack.push(make_pair(root, false));
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        while (!my_stack.empty()) {
            pair<TreeNode*, bool> temp = my_stack.top();
            my_stack.pop();
            if (temp.second) {
                ans.push_back(temp.first -> val);
                if (temp.first->right != NULL){
                    my_stack.push(make_pair(temp.first->right, false));
                }
            } else {
                temp.second = true;
                my_stack.push(temp);
                if (temp.first->left != NULL){
                    my_stack.push(make_pair(temp.first->left, false));
                }
            }
        }
        return ans;
    }
    */
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> my_stack;
        vector<int> ans;
        TreeNode* cur = root;
        while (cur != NULL || !my_stack.empty()) {
            while (cur != NULL) {
                my_stack.push(cur);
                cur = cur->left;
            }
            cur = my_stack.top();
            my_stack.pop();
            ans.push_back(cur->val);
            cur = cur->right;
        }
        return ans;
    }
};
