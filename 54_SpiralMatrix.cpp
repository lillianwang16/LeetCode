class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>> dir{{0, 1},{1, 0},{0, -1},{-1, 0}};
        int m = matrix.size(), n = m == 0? 0 : matrix[0].size();
        vector<int> ans;
        if (m == 0 || n == 0) {
            return ans;
        }
        vector<int> remain{n, m - 1};
        int cur_dir = 0, x = 0, y = -1;
        while (remain[cur_dir % 2] > 0) {
            for (int i = 0; i < remain[cur_dir % 2]; ++i) {
                x += dir[cur_dir][0];
                y += dir[cur_dir][1];
                ans.push_back(matrix[x][y]);
            }
            --remain[cur_dir % 2];
            cur_dir = (cur_dir + 1) % 4;
        }
        return ans;
    }
};
