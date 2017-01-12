/*
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0, max_xor = 0;
        for (int i = 31; i >= 0; --i) {
            unordered_set<int> cnt;
            mask |= (1 << i);
            for (int j : nums) {
                cnt.insert(j & mask);
            }
            if (!cnt.empty()) {
                int temp = max_xor | (1 << i);
                for (int j : cnt) {
                    if (cnt.find(temp ^ j) != cnt.end()) {
                        max_xor = temp;
                        break;
                    }
                }
            }
        }
        return max_xor;
    }
};
*/

//Solution using Trie.
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        TrieNode* cur_node;
        for (int num : nums) {
            cur_node = root;
            for (int i = 31; i >= 0; --i) {
                int cur_bit = (num >> i) & 1;
                if (cur_node->next[cur_bit] == NULL) {
                    cur_node->next[cur_bit] = new TrieNode();
                }
                cur_node = cur_node->next[cur_bit];
            }
        }
        int max_xor = 0;
        for (int num : nums) {
            cur_node = root;
            int temp = 0;
            for (int i = 31; i >= 0; --i) {
                int cur_bit = (num >>i) & 1;
                if (cur_node->next[cur_bit ^ 1] != NULL) {
                    temp |= (1 << i);
                    cur_node = cur_node->next[cur_bit ^ 1];
                } else {
                    cur_node = cur_node->next[cur_bit];
                }
            }
            max_xor = max(max_xor, temp);
        }
        return max_xor;
    }
private:
    struct TrieNode {
        TrieNode* next[2];
        TrieNode () {next[0] = NULL; next[1] = NULL;}
    };
};



