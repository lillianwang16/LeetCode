//"if we put n as the last number then all the k inverse pair should come from the first n-1 numbers."
class Solution {
public:
    int kInversePairs(int n, int k) {
        int N = 1000000007;
        if (k > n * (n - 1) / 2 || k < 0)   return 0;
        if (k == 0 || k == n * (n - 1) / 2) return 1;
        vector<vector<int>> dp(n + 1, vector<int> (k + 1));
        dp[2][0] = 1;
        dp[2][1] = 1;
        for (int i = 3; i <= n; ++i) {
            dp[i][0] = 1;
            for (int j = 1; j <= min(k, i * (i - 1) / 2); ++j) {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % N; // (dp + dp + N) could exceed the INT_MAX.
                if (j >= i) {
                    dp[i][j] -= dp[i - 1][j - i]; // Because of mod, dp[i][j] could be less than dp[i - 1][j - i].
                }
                dp[i][j] = (dp[i][j] + N) % N;
            }
        }
        return dp[n][k];
    }
};