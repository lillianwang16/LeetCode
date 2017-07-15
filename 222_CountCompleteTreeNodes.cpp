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
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL)   return 0;
        count(root, 0);
        return pow(2, height) - 1 + l;
    }
private:
    int height = 0;
    int l = 0;
    bool flag = false;
    void count(TreeNode* cur, int step) {
        if (cur->left == NULL) {
            if (step < height) {
                flag = true;
                return;
            }
            height = step;
            ++l;
            return;
        }
        if (!flag) {
            count(cur->left, step + 1);
        }
        if (!flag && cur->right != NULL) {
            count(cur->right, step + 1);
        }
    }
};
*/

/*
// Binary search.
class Solution {
public:
    int countNodes(TreeNode* root) {
        int h = height(root);
        if (h == 0) return 0;
        int h_r = height(root->right);
        if (h_r == h - 1) {
            return (1 << h - 1) + countNodes(root->right);
        } else {
            return (1 << h_r) + countNodes(root->left);
        }
    }
private:
    int height(TreeNode* cur) {
        return cur == NULL ? 0 : 1 + height(cur->left); 
    }
};
*/

//Iterative solution.
class Solution {
public:
    int countNodes(TreeNode* root) {
        int res = 0;
        while (root != NULL) {
            int h = height(root);
            int hr = height(root->right);
            if (h == hr + 1) {
                res += (1 << hr);
                root = root->right;
            } else {
                res += (1 << hr);
                root = root->left;
            }
        }
        return res;
    }
private:
    int height(TreeNode* cur) {
        return cur == NULL ? 0 : 1 + height(cur->left); 
    }
};