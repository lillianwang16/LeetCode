/*
//using a queue for recording the last two rows
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size() == 0 || board[0].size() == 0)  
            return;
        queue<int> rec;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (i >= 2) {
                    board[i - 2][j] = rec.front();
                    rec.pop();
                }
                int result = checkNeighbors(board, i, j);
                rec.push(result);
            }
        }
        for (int i = board.size() - rec.size() / board[0].size(); i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                board[i][j] = rec.front();
                rec.pop();
            }
        }
    }
private:
    int checkNeighbors(vector<vector<int>>& board, int x, int y) {
        int cnt = 0;
        for (int i = x - 1; i <= x + 1; ++i) {
            for (int j = y - 1; j <= y + 1; ++j) {
                if (i >= 0 && j >= 0 && i < board.size() && j < board[0].size() && board[i][j])  {
                    ++cnt;
                }
            }
        }
        if (board[x][y]) {
            --cnt;
            if (cnt < 2 || cnt > 3) 
                return 0;
            return 1;
        } else {
            if (cnt == 3)
                return 1;
            return 0;
        }
    }
};
*/
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = m ? board[0].size() : 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int lives = 0;
                for (int x = max(i - 1, 0); x <= min(i + 1, m - 1); ++x) {
                    for (int y = max(j - 1, 0); y <= min(j + 1, n - 1); ++y) {
                        if (board[x][y] & 1) {
                            ++lives;
                        }
                    }
                }
                if (lives == 3 || lives - board[i][j] == 3) {
                    board[i][j] |= 2;
                }
            }           
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};

