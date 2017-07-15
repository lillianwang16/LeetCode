class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, true));
        vector<vector<int>> path(m, vector<int> (n, -1));
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, DFS(matrix, path, visited, i, j));
            }
        }
        return res;
    }
private:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int DFS(vector<vector<int>>& matrix, vector<vector<int>>& path, vector<vector<bool>>& visited, int i, int j) {
        if (path[i][j] != -1) {
            return path[i][j];
        }
        visited[i][j] = false;
        int num = 1;
        for (int k = 0; k < 4; ++k) {
            int row = i + dir[k][0];
            int col = j + dir[k][1];
            if (row >= 0 && row < matrix.size() && col >=0 && col < matrix[0].size() && visited[row][col] && matrix[i][j] >  matrix[row][col]) {
                num = max(num, 1 + DFS(matrix, path, visited, row, col));
            }
        }
        visited[i][j] = true;
        path[i][j] = num;
        return num;
    }
};