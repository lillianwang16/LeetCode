class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    floodfill(grid, i, j);
                    ++cnt;
                }
            }
        }
        return cnt;
    }
private:
    void floodfill(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1')
            return;
        grid[i][j] = '0';
        floodfill(grid, i + 1, j);
        floodfill(grid, i - 1, j);
        floodfill(grid, i, j + 1);
        floodfill(grid, i, j - 1);
    }
};
