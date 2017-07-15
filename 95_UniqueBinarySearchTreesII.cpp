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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        res = generateTrees(1, n);
        return res;
    }
private:
    vector<TreeNode*> generateTrees(int i, int j) {
        vector<TreeNode*> res;
        if (i > j) {
            return res;
        }
        for (int cur = i; cur <= j; ++cur) {
            vector<TreeNode*> left = generateTrees(i, cur - 1);
            vector<TreeNode*> right = generateTrees(cur + 1, j);
            if (left.empty() && right.empty()) {
                res.push_back(new TreeNode(cur));
            } else if (!left.empty() && right.empty()) {
                for (TreeNode* l : left) {
                    TreeNode *curNode = new TreeNode(cur);
                    curNode->left = l;
                    res.push_back(curNode);
                }
            } else if (left.empty() && !right.empty()) {
                    for (TreeNode* r : right) {
                    TreeNode *curNode = new TreeNode(cur);
                    curNode->right = r;
                    res.push_back(curNode);
                }
            } else {
                for (TreeNode* l : left) {
                    for (TreeNode* r : right) {
                        TreeNode *curNode = new TreeNode(cur);
                        curNode->right = r;
                        curNode->left = l;
                        res.push_back(curNode);
                    }
                }
            }
        }
        return res;
    }
};