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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> hm;
        for (int i = 0; i < inorder.size(); ++i) {
            hm[inorder[i]] = i;
        }
        return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, hm);       
    }
private:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int s1, int e1, int s2, int e2, unordered_map<int, int>& hm) {
        if (e1 < s1) {
            return NULL;
        }
        int v = postorder[e2];
        TreeNode* cur = new TreeNode(v);
        int p = hm[v];
        cur->left  = buildTree(inorder, postorder, s1, p - 1, s2, s2 + (p - 1 - s1), hm);
        cur->right = buildTree(inorder, postorder, p + 1, e1, s2 + (p - s1), e2 - 1, hm);
        return cur;
    }
};