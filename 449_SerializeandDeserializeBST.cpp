tion for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str;
        serializePreorder(root, str);
        return str;
    }
    void serializePreorder(TreeNode* node, string& str) {
        if (node == NULL) {
            return;
        }
        str += to_string(node->val) + '.';
        serializePreorder(node->left, str);
        serializePreorder(node->right, str);
        return;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return deserializePreorder(data, INT_MIN, INT_MAX, pos);
    }
    TreeNode* deserializePreorder(const string& data, int lo, int hi, int& pos) {
        if (pos == data.size()) {
            return NULL;
        }
        int val = 0, cur_pos = pos;;
        while (data[cur_pos] != '.') {
            val = val * 10 + data[cur_pos] - '0';
            ++cur_pos;
        }
        ++cur_pos;
        if (val < lo || val > hi) {
            return NULL;
        }
        pos = cur_pos;
        TreeNode* node = new TreeNode(val);
        node->left = deserializePreorder(data, lo, val, pos);
        node->right = deserializePreorder(data, val, hi, pos);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
