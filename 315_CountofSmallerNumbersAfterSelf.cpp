class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int l = nums.size();
        vector<int> res(l);
        if (l == 0) return res;
        TreeNode* root = new TreeNode(nums[l - 1]);
        for (int i = l - 2; i >= 0; --i) {
            res[i] = add(root,nums[i]);
        }
        return res;
    }
private:
    struct TreeNode {
        int val;
        int ln, dup;
        TreeNode *left, *right;
        TreeNode(int v): val(v), dup(1), ln(0), left(NULL), right(NULL){}
    }; 
    int add(TreeNode* cur, int key) {
        if (cur->val == key) {
            ++cur->dup;
            return cur->ln;
        } else if (key > cur->val) {
            if (cur->right == NULL) {
                cur->right = new TreeNode(key);
                return cur->dup + cur->ln;
            }
            return cur->dup + cur->ln + add(cur->right, key);
        } else if (key < cur->val) {
            ++cur->ln;
            if (cur->left == NULL) {
                cur->left = new TreeNode(key);
                return 0;
            }
            return add(cur->left, key);
        }
        
    }
};
