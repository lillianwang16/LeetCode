class Solution {
public:
    bool isMatch(string s, string p) {
        int a = s.length(), b = p.length();
        vector<vector<bool>> dp(a + 1, vector<bool> (b + 1));
        dp[0][0] = true;
        for (int j = 2; j <= b; ++j) {
            dp[0][j] = dp[0][j - 2] && p[j - 1] == '*';
        }
        for (int i = 1; i <= a; ++i) {
            for (int j = 1; j <= b; ++j) {
                if (p[j - 1] != '*') {
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                } else {
                    dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                }
            }
        }
        return dp[a][b];
    }
};
