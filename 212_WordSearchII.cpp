class TrieNode{
public:
    vector<TrieNode*> next;
    string word;
    TrieNode(): next(vector<TrieNode*> (26)), word(){}
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        TrieBuilder(root, words);
        vector<string> ans;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                DFS(board, ans, root, i, j);
            }
        }
        return ans;
    }
private:
    void DFS(vector<vector<char>>& board, vector<string>& ans, TrieNode* cur, int i, int j) {
        char c = board[i][j];
        if (c == '#' || cur->next[c - 'a'] == NULL) {
            return;
        }
        cur = cur->next[c- 'a'];
        if (cur->word != "") {
            ans.push_back(cur->word);
            cur->word = "";
        }
        board[i][j] = '#';
        if (i > 0)  DFS(board, ans, cur, i - 1, j);
        if (j > 0)  DFS(board, ans, cur, i, j - 1);
        if (i < board.size() - 1)       DFS(board, ans, cur, i + 1, j);
        if (j < board[0].size() - 1)   DFS(board, ans, cur, i, j + 1);
        board[i][j] = c;
    }
    void TrieBuilder(TrieNode* root, vector<string>& words) {
        for (string word : words) {
            TrieNode* cur = root;
            for (int i = 0; i < word.length(); ++i) {
                if (cur->next[word[i] - 'a'] == NULL) {
                    cur->next[word[i] - 'a'] = new TrieNode();
                }
                cur = cur->next[word[i] - 'a'];
            }
            cur->word = word;
        }
    }
};

