class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> visited1(9, vector<bool>(9, false));
        vector<vector<bool>> visited2(9, vector<bool>(9, false));
        vector<vector<bool>> visited3(9, vector<bool>(9, false));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    int s = (i / 3) * 3 + j / 3;
                    if (visited1[i][num] || visited2[j][num]|| visited3[s][num]) {
                        return false;
                    }
                    visited1[i][num] = true;
                    visited2[j][num] = true;
                    visited3[s][num] = true;
                }
            }
        }
        return true;
    }
};
