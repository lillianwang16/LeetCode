/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 /*
 //Recursive solution.
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) 
            return;
        TreeLinkNode *cur_left = root->left, *cur_right = root->right;
        while (cur_left != NULL && cur_right != NULL) {
            cur_left->next = cur_right;
            cur_left = cur_left->right;
            cur_right = cur_right->left;
        }
        connect(root->left);
        connect(root->right);
    }
};
*/
//Iterative Solutions.
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) {
            return;
        }
        TreeLinkNode *prev = root, *cur = NULL;
        while (prev->left != NULL) {
            cur = prev;
            while (cur != NULL) {
                cur->left->next = cur->right;
                if (cur->next != NULL) {
                    cur->right->next = cur->next->left;
                }
                cur = cur->next;
            }
            prev = prev->left;
        }
    }
};
