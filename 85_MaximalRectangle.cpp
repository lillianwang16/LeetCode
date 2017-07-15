/*
// Save the length of each row and then compute the largest.
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = m == 0 ? 0 : matrix[0].size();
        if (m == 0 || n == 0) return 0;
        vector<vector<int>> num(m, vector<int> (n));
        for (int i = m - 1; i >= 0; --i) {
            int cnt = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    ++cnt;
                } else {
                    cnt = 0;
                }
                num[i][j] = cnt;
            }
        }
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (num[i][j] == 0) continue;
                int col = num[i][j];
                for (int row = 1; i + row - 1 < m; ++row) {
                    if (num[i + row - 1][j] == 0) break;
                    col = min(col, num[i + row - 1][j]);
                    res = max(res, row * col);
                }
            }
        }
        return res;
    }
};
*/
// Save the length each row both from left and right.
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = m == 0 ? 0 : matrix[0].size();
        if (m == 0 || n == 0) return 0;
        vector<int> left(n, 0);
        vector<int> right(n, n);
        vector<int> height(n, 0);
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') {
                    height[j] = 0;
                } else {
                    ++height[j];
                }
            }
            int cur_left = 0, cur_right = n;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], cur_left);
                } else {
                    left[j] = 0;
                    cur_left = j + 1;
                }
            }
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], cur_right);
                } else {
                    right[j] = n;
                    cur_right = j;
                }
            }
            for (int j = 0; j < n; ++j) {
                res = max(res, (right[j] - left[j]) * height[j]);
            }
        }
        return res;
    }
};