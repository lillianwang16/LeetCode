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
//In-order iterative solution. 
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* cur_node = root;
        int cnt = 0;
        while(cur_node != NULL || !s.empty()) {
            while (cur_node != NULL) {
                s.push(cur_node);
                cur_node = cur_node->left;
            }
            cur_node = s.top();
            s.pop();
            ++cnt;
            if (cnt == k) {
                break;
            }
            cur_node = cur_node->right;
        }
        return cur_node->val;
    }
};
*/

//Binary-search solution.
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = count(root->left);
        if (k <= cnt) {
            return  kthSmallest(root->left, k);
        } 
        if (k > cnt + 1) {
            return  kthSmallest(root->right, k - cnt - 1);
        }
        return root->val;
    }
private:
    int count(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        return 1 + count(node->left) + count(node->right);
    }
};

