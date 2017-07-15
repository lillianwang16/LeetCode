class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0) return false;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (DFS(board, i, j, word, 0)) {
                    return true;
                };
            }
        }
        return false;
    }
private:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool DFS(vector<vector<char>>& board, int i, int j, string word, int p) {
        if (board[i][j] != word[p]) {
            return false;
        }
        if (p == word.length() - 1) {
            return true;
        }
        char c = board[i][j];
        board[i][j] = '#';
        for (int k = 0; k < 4; ++k) {
            int ii = i + dir[k][0];
            int jj = j + dir[k][1];
            if (ii >= 0 && jj >= 0 && ii < board.size() && jj < board[0].size()) {
                if (DFS(board, ii, jj, word, p + 1)) {
                    return true;
                }
            }
        }
        board[i][j] = c;
        return false;
    } 
};
