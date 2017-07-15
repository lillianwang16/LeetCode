/*
// Using the solution to count the largest rectangle.
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0|| matrix[0].size() == 0) return 0;
        int row = matrix.size(), col = matrix[0].size();
        vector<int> left(col, 0), right(col, col), height(col, 0);
        int res = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '0') {
                    height[j] = 0;
                } else {
                    ++height[j];
                }
            }
            int l = 0, r = col;
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '0') {
                    l = j + 1;
                    left[j] = 0;
                } else {
                    left[j] = max(l, left[j]);
                }
            }
            for (int j = col - 1; j >= 0; --j) {
                if (matrix[i][j] == '0') {
                    r = j;
                    right[j] = col;
                } else {
                    right[j] = min(r, right[j]);
                }
            }
            for (int j = 0; j < col; ++j) {
                res = max(res, min(height[j], right[j] - left[j]));
            }
        }
        return res * res;
    }
};
*/

//DP solution.
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0|| matrix[0].size() == 0) return 0;
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int> (col));
        int res = 0;
        for (int i = 0; i < col; ++i) {
            if (matrix[0][i] == '1') {
                dp[0][i] = 1;
                res = max(res, dp[0][i]);
            }
        }
        for (int i = 0; i < row; ++i) {
            if (matrix[i][0] == '1') {
                dp[i][0] = 1;
                res = max(res, dp[i][0]);
            }
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                    res = max(res, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return res * res;
    }
};
