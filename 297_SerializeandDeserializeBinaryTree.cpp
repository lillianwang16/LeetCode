/**
 * Definition for a binary tree node.
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
        if (root == NULL) {
            return ".";
        }
        string s = to_string(root->val);
        string s1 = serialize(root->left);
        string s2 = serialize(root->right);
        return s + "," + s1 + s2;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return deserializeHelper(data);
    }
private:
    TreeNode* deserializeHelper(string& data) {
        if (data[0] == '.') {
            data = data.substr(1);
            return NULL;
        }
        string s;
        int i = 0;
        for (; i < data.length(); ++i) {
            if (data[i] == ',') {
                ++i;
                break;
            }
        }
        s = data.substr(0, i - 1);
        TreeNode* cur = new TreeNode(stoi(s));
        data = data.substr(i);
        cur->left = deserializeHelper(data);
        cur->right = deserializeHelper(data);
        return cur;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
