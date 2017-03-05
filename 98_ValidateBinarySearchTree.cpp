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
//Set the valid range of root value.
//INT_MIN should not be used to avoid overflow.
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, (long)INT_MIN - 1, (long)INT_MAX + 1);
    }
    bool isValidBST(TreeNode* root, long low, long high) {
        if (root == NULL)
            return true;
        int flag = root->val > low && root->val < high;
        if (root->left != NULL) {
            flag &= isValidBST(root->left, low, root->val);
        }
        if (root->right != NULL) {
            flag &= isValidBST(root->right, root->val, high);
        }
        return flag;
    }
};
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return isValidBST(root, prev);
    }
    bool isValidBST(TreeNode* root, TreeNode* &prev) {
        if (root == NULL) {
            return true;
        }
        if (!isValidBST(root->left, prev)) {
            return false;
        }
        if (prev != NULL && prev->val >= root->val) {
            return false;
        }
        prev = root;
        return (isValidBST(root->right, prev));
    }
};
