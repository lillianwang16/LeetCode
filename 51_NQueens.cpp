class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        nQueens(n, 0, board);
        return Queens_;
    }
private:
    vector<vector<string> > Queens_;
    bool checkPosition(int i0, int j0, const vector<string>& board) {
        for (int i = 0; i < (int)board.size(); ++i) {
            if (board[i][j0] == 'Q') {
                return false;
            }
            int j1 = i + (j0 - i0), j2 = (i0 + j0) - i;
            if (j1 >=0 && j1 <= board.size() && board[i][j1] == 'Q') {
                return false;
            }
            if (j2 >=0 && j2 <= board.size() && board[i][j2] == 'Q') {
                return false;
            }
        
        }
        return true;
    }
    void nQueens(int n, int step, vector<string>& board) {
        if (step >= n) {
            Queens_.push_back(board);
            return;
        }
        int i = step;
        for (int j = 0; j < n; ++j) {
            if (checkPosition(i, j, board)) {
                board[i][j] = 'Q';
                nQueens(n, step + 1, board);
                board[i][j] = '.';
            }
        }
        return;
    }
};
