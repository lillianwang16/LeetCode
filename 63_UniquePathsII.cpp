class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = m == 0 ? 0 : obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n));
        dp[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] += (i - 1) < 0 ? 0 : dp[i - 1][j];
                dp[i][j] += (j - 1) < 0 ? 0 : dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};