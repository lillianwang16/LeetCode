ass Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        vector<vector<int>> x(grid.size(), vector<int>(grid[0].size()));
        vector<vector<int>> y(grid.size(), vector<int>(grid[0].size()));
        for (int i = 0; i < grid.size(); ++i) {
            int start_w = -1, end_w = 0, cnt = 0;
            while (end_w <= grid[0].size()) {
                if (end_w < grid[0].size() && grid[i][end_w] == 'E') {
                    ++cnt;
                } else if (end_w == grid[0].size() || grid[i][end_w] == 'W') {
                    for (int j = start_w + 1; j < end_w; ++j) {
                        if (grid[i][j] == '0') {
                            x[i][j] = cnt;
                        } else {
                            x[i][j] = -1;
                        }
                    }
                    cnt = 0;
                    start_w = end_w;
                }
                ++end_w;
            }
        }
        for (int j = 0; j < grid[0].size(); ++j) {
            int start_w = -1, end_w = 0, cnt = 0;
            while (end_w <= grid.size()) {
                if (end_w < grid.size() && grid[end_w][j] == 'E') {
                    ++cnt;
                } else if (end_w == grid.size() || grid[end_w][j] == 'W') {
                    for (int i = start_w + 1; i < end_w; ++i) {
                        if (grid[i][j] == '0') {
                            y[i][j] = cnt;
                        } else {
                            y[i][j] = -1;
                        }
                    }
                    cnt = 0;
                    start_w = end_w;
                }
                ++end_w;
            }
        }
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (x[i][j] != -1 && y [i][j] != -1) {
                    ans = max(ans, x[i][j] + y[i][j]);
                }
            }
        }
        return ans;
    }
};
*/
//Solution using an array.
class Solution {
    public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int ans = 0, row_num = 0, m = grid.size(), n = grid[0].size();
        vector<int> col_num(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0 || grid[i][j - 1] == 'W') {
                    row_num = 0;
                    for (int k = j; k < n && grid[i][k] != 'W'; ++k) {
                        row_num += (grid[i][k] == 'E');
                    }
                }
                if (i == 0 || grid[i - 1][j] == 'W') {
                    col_num[j] = 0;
                    for (int k = i; k < m && grid[k][j] != 'W'; ++k) {
                        col_num[j] += (grid[k][j] == 'E');
                    }
                }
                if (grid[i][j] == '0') {
                    ans = max(ans, row_num + col_num[j]);
                }
            }
        }
        return ans;
    }
};
